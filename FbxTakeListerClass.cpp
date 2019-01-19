#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
//#include <fbxsdk.h>

using namespace std;

class FbxTakeNameList
{
    public:
    FbxTakeNameList (std::string* FbxFileName); 
    FbxTakeNameList ();
    ~FbxTakeNameList ();
    void fnOutputTakeNameList ();             // list all take names
    void fnSearchForTake (std::string* TakeName);  //search for one take in search result list
    
    private:
    std::vector<std::string>* pvecTakesList;                        // string array with take search result
    std::vector<std::string>::iterator itvecCurTake;                // pointer to access the search result string
    std::vector<std::string>* fnListTakesFBX (std::string* FbxFileName); //MAIN# function returns the take name string array from given file using FBX SDK
    
};

FbxTakeNameList::FbxTakeNameList () {
    std::cout << " DEBUG: noparam-constructor " <<std::endl;
}

FbxTakeNameList::~FbxTakeNameList () {
    std::cout << " DEBUG: destructor " << std::endl << std::endl;
    delete pvecTakesList;
}

FbxTakeNameList::FbxTakeNameList (std::string* FbxFileName)
{
    std::cout << " DEBUG: constructor with FbxFileName: " <<std::endl;
    pvecTakesList = fnListTakesFBX (FbxFileName);
}

std::vector<std::string>* FbxTakeNameList::fnListTakesFBX (std::string* FbxFileName)
{
    std::cout << " DEBUG: func called by constructor with param:"<< std::endl;
    std::vector<std::string>* pvecSearchResult = new std::vector<std::string>;   //pointer to string array in heap, don't forget to release memory after function closeing
    /*----------------------FBX SDK code-------------------------------------
	FbxManager *lSdkManager = FbxManager::Create();
	FbxIOSettings * ios = FbxIOSettings::Create(lSdkManager, IOSROOT );
     // set some IOSettings options 
     //ios->SetBoolProp(IMP_FBX_MATERIAL, true);
     //ios->SetBoolProp(IMP_FBX_TEXTURE,  true);
     // create an empty scene
     //FbxScene* lScene = FbxScene::Create(lSdkManager,"");
     // Create an importer.
     FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");
     // Initialize the importer by providing a filename and the IOSettings to use
     lImporter->Initialize("D:\\PROJECTS\\FBX_Takes_Lister_Standalone\\test.fbx", -1, ios);
     // Import the scene.
     //lImporter->Import(lScene); 
    // Ex: to get all take names in a FBX file
     for(int lAnimStackCount=0; lAnimStackCount < lImporter->GetAnimStackCount(); lAnimStackCount++) 
     {
       FbxTakeInfo* lTakeInfo = lImporter->GetTakeInfo(lAnimStackCount);
       FbxString lTakeName = lTakeInfo->mName;
	   std::string buff = lTakeName;
       pvecTakesList-> push_back (buff);	   
     }
     // Destroy the importer.
     lImporter->Destroy(); 
    --------------------------------------------------------------------*/
    pvecSearchResult-> push_back("one");  //debuging part: pushing found take name into resulting array
    pvecSearchResult-> push_back("two");
    pvecSearchResult-> push_back("three");
    pvecSearchResult-> push_back("end");
    return (pvecSearchResult);  //return pointer to result string array
}

void FbxTakeNameList::fnOutputTakeNameList ()
{
    std::cout << " DEBUG: fnOutputTakeNames:  " <<std::endl;
    /* itvecCurTake = pvecTakesList->begin();
     while (itvecCurTake != pvecTakesList->end())
     {
		 std::string buff = *itvecCurTake;
         std::cout << "    DEBUG: search result: " << &buff[0] << std::endl;
         ++itvecCurTake;
		 
     }*/
}

void FbxTakeNameList::fnSearchForTake (std::string* TakeName)
{

    std::cout << " DEBUG: fnSearchForTake:  " <<std::endl;/*
    itvecCurTake = pvecTakesList->begin();
    while (itvecCurTake != pvecTakesList->end())
    {
        cout << "    DEBUG: search for take: compare " << *itvecCurTake <<" and " << *TakeName << endl;
        if (*itvecCurTake==*TakeName)  // put more complicated comparition here by part of name
        {
            cout << "          DEBUG:  TRUE" << endl;
        }
        ++itvecCurTake;
    }*/
}