#pragma once

#include "stdafx.h"
#include "Form1.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fbxsdk.h>









class FbxTakeNameList  // creates list of all take or search match takes from specified .fbx file
{
    public:
    FbxTakeNameList (std::string* FbxFileName); 
    FbxTakeNameList ();
    ~FbxTakeNameList ();
    std::string fnOutputTakeNameList ();             // list all take names
    std::string fnSearchForTake (std::string TakeName);  //search for one take in search result list
    
    private:
    std::vector<std::string> pvecTakesList;                        // string array with take search result
    std::vector<std::string>::iterator itvecCurTake;                // pointer to access the search result string
    void fnListTakesFBX (std::string* FbxFileName); //MAIN# function returns the take name string array from given file using FBX SDK
    
};


FbxTakeNameList::FbxTakeNameList () {
    std::cout << " DEBUG: noparam-constructor " <<std::endl;
}

FbxTakeNameList::~FbxTakeNameList () {
    std::cout << " DEBUG: destructor " << std::endl << std::endl;
    //delete pvecTakesList;
}

FbxTakeNameList::FbxTakeNameList (std::string* FbxFileName)
{
    //std::cout << " DEBUG: constructor with FbxFileName: " <<std::endl;
    fnListTakesFBX (FbxFileName);
}

void FbxTakeNameList::fnListTakesFBX (std::string* FbxFileName)
{
    //std::cout << " DEBUG: func called by constructor with param:"<< std::endl;
    //std::vector<std::string>* pvecSearchResult = new std::vector<std::string>; //pointer to string array in heap, don't forget to release memory after function closeing 
	//----------------------FBX SDK code-------------------------------------
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
     lImporter->Initialize(FbxFileName->c_str(), -1, ios);
     // Import the scene.
     //lImporter->Import(lScene); 
    // Ex: to get all take names in a FBX file
     for(int lAnimStackCount=0; lAnimStackCount < lImporter->GetAnimStackCount(); lAnimStackCount++) 
     {
       FbxTakeInfo* lTakeInfo = lImporter->GetTakeInfo(lAnimStackCount);
       FbxString lTakeName = lTakeInfo->mName;
	   std::string buff = lTakeName;
       pvecTakesList.push_back (buff);	   
     }
     // Destroy the importer.
     lImporter->Destroy(); 
    //--------------------------------------------------------------------
    /*pvecTakesList.push_back("one");  //debuging part: pushing found take name into resulting array
    pvecTakesList.push_back("two");
    pvecTakesList.push_back("three");
    pvecTakesList.push_back("end");*/
    //return (pvecSearchResult);  //return pointer to result string array
}

std::string FbxTakeNameList::fnOutputTakeNameList ()
{
    std::string buff = "";
    itvecCurTake = pvecTakesList.begin();
     while (itvecCurTake != pvecTakesList.end())
     {      
		 buff.append (*itvecCurTake);
		 buff+= "\n";
        // std::cout << "    DEBUG: search result: " << &buff[0] << std::endl;
        ++itvecCurTake; 
	 } 
    return buff;
}

std::string FbxTakeNameList::fnSearchForTake (std::string TakeName)
{

    std::string strTakeList = fnOutputTakeNameList ();
	std::string strSearchResult = "";
	std::string buff = "";
	std::istringstream strmResultList(strTakeList);    //string to stream for line by line search
	while (std::getline(strmResultList, buff)) 
	{
		std::size_t matchIndex = buff.find (TakeName);
   		if (strTakeList.length()>=2 && matchIndex!=std::string::npos) 
		{
			strSearchResult.append (buff);
			strSearchResult.append ("\n");
		}
	}
	if (!strSearchResult.length()) {	strSearchResult = " - no takes found \n";};
	return strSearchResult;

}
//----------------------------------------------------------------------------------