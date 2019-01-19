#pragma once

#include "FbxTakeLister.h"
#include <msclr\marshal_cppstd.h>
 

using namespace std;



//--------------------------------------------------------------------------------------
namespace FbxTakeListerForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		
		Form1(void)
		{
			InitializeComponent();
		
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  splitContainer1;

	private: System::Windows::Forms::Button^  btnFolderSearch;
	private: System::Windows::Forms::Button^  btnFileSearch;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  btnListTakesInFolder;
	private: System::Windows::Forms::Button^  btnListAllTakes;
	public: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	public: 


	private: System::ComponentModel::IContainer^  components;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->btnListTakesInFolder = (gcnew System::Windows::Forms::Button());
			this->btnListAllTakes = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnFolderSearch = (gcnew System::Windows::Forms::Button());
			this->btnFileSearch = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->label2);
			this->splitContainer1->Panel1->Controls->Add(this->btnListTakesInFolder);
			this->splitContainer1->Panel1->Controls->Add(this->btnListAllTakes);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->btnFolderSearch);
			this->splitContainer1->Panel1->Controls->Add(this->btnFileSearch);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->textBox2);
			this->splitContainer1->Size = System::Drawing::Size(253, 401);
			this->splitContainer1->SplitterDistance = 87;
			this->splitContainer1->TabIndex = 0;
			// 
			// btnListTakesInFolder
			// 
			this->btnListTakesInFolder->Location = System::Drawing::Point(129, 65);
			this->btnListTakesInFolder->Name = L"btnListTakesInFolder";
			this->btnListTakesInFolder->Size = System::Drawing::Size(120, 21);
			this->btnListTakesInFolder->TabIndex = 6;
			this->btnListTakesInFolder->Text = L"List all Takes in Folder";
			this->btnListTakesInFolder->UseVisualStyleBackColor = true;
			this->btnListTakesInFolder->Click += gcnew System::EventHandler(this, &Form1::btnListTakesInFolder_Click);
			// 
			// btnListAllTakes
			// 
			this->btnListAllTakes->Location = System::Drawing::Point(3, 65);
			this->btnListAllTakes->Name = L"btnListAllTakes";
			this->btnListAllTakes->Size = System::Drawing::Size(120, 21);
			this->btnListAllTakes->TabIndex = 5;
			this->btnListAllTakes->Text = L"List all Takes in File";
			this->btnListAllTakes->UseVisualStyleBackColor = true;
			this->btnListAllTakes->Click += gcnew System::EventHandler(this, &Form1::btnListAllTakes_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Take Name:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(3, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(246, 20);
			this->textBox1->TabIndex = 3;
			// 
			// btnFolderSearch
			// 
			this->btnFolderSearch->Location = System::Drawing::Point(129, 38);
			this->btnFolderSearch->Name = L"btnFolderSearch";
			this->btnFolderSearch->Size = System::Drawing::Size(120, 21);
			this->btnFolderSearch->TabIndex = 1;
			this->btnFolderSearch->Text = L"Search in Folder";
			this->btnFolderSearch->UseVisualStyleBackColor = true;
			this->btnFolderSearch->Click += gcnew System::EventHandler(this, &Form1::btnFolderSearch_Click);
			// 
			// btnFileSearch
			// 
			this->btnFileSearch->Location = System::Drawing::Point(3, 38);
			this->btnFileSearch->Name = L"btnFileSearch";
			this->btnFileSearch->Size = System::Drawing::Size(120, 21);
			this->btnFileSearch->TabIndex = 0;
			this->btnFileSearch->Text = L"Search in File";
			this->btnFileSearch->UseVisualStyleBackColor = true;
			this->btnFileSearch->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(0, 1);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(253, 308);
			this->textBox2->TabIndex = 0;
			this->textBox2->Click += gcnew System::EventHandler(this, &Form1::textBox2_Click);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->Description = L"Select Search Folder:";
			this->folderBrowserDialog1->RootFolder = System::Environment::SpecialFolder::MyComputer;
			this->folderBrowserDialog1->ShowNewFolderButton = false;
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &Form1::folderBrowserDialog1_HelpRequest);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"fbx file|*.fbx";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(189, 52);
			this->label2->TabIndex = 7;
			this->label2->Text = L"FBX SDK 2015.1 and .NETFramework\r\nreport bugs and issues to:\r\nundecima.novembris@" 
				L"gmail.com\r\nDmytro Ishchenko";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(253, 401);
			this->Controls->Add(this->splitContainer1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->Text = L"FBX Take Search Tool";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
			 //----------------------search in 1 file------------------------------------
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (textBox1->Text=="") 
				 {   textBox2->Text="";
					 textBox2->AppendText("   - Enter search take name");
					 return;}
			 	openFileDialog1->ShowDialog() ;
				std::string* buff = new std::string (marshal_as<string>(openFileDialog1->FileName));
			    FbxTakeNameList  FBXTakeSearchObj (buff);

			    *buff = 	FBXTakeSearchObj.fnSearchForTake(marshal_as<string>(textBox1->Text));
				textBox2->AppendText ("   - Takes search result of: ");
				textBox2->AppendText  (textBox1->Text);
				textBox2->AppendText ("\n");
			    std::istringstream strmResultList(*buff);    //output line by line to textbox
			    while (std::getline(strmResultList, *buff)) {
			    textBox2->AppendText (marshal_as<String^>(*buff));  //use this shit to match std::string with CLI's System::String^
			    textBox2->AppendText ("\n");
			    }
			    textBox2->AppendText ("\n");
			    delete buff;



			 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			//textBox2->Text = "";
			textBox2->Text = openFileDialog1->FileName;
			textBox2->AppendText ("\n");
			textBox2->AppendText ("\n");
		 }
		 //--------------------search in Folder--------------------------------------
private: System::Void btnFolderSearch_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (textBox1->Text=="") 
				 {   textBox2->Text="";
					 textBox2->AppendText("   - Enter search take name");
					 return;}
			 folderBrowserDialog1->ShowDialog() ;
			 textBox2->Text = "";
			 textBox2->AppendText ("    - Folder:\n");
			 textBox2->AppendText (folderBrowserDialog1->SelectedPath);
			 textBox2->AppendText ("\n");
			 textBox2->AppendText ("\n   - Search for take: ");
			 textBox2->AppendText  (textBox1->Text);
			 textBox2->AppendText ("\n");
			 textBox2->AppendText ("\n");

			 String^ folder = folderBrowserDialog1->SelectedPath;  //  list all file in folder. part from MSDN
			 array<String^>^ file = Directory::GetFiles( folder ); //
	
			    for (int i=0; i<file->Length; i++)
				{    
					if (file[i]->Contains(".fbx"))
					{

						textBox2->AppendText(file[i]);
						textBox2->AppendText (":\n");
						System::String^ tmpFileName = file[i];						
						FbxTakeNameList  FBXTakeSearchObj (&marshal_as<string>(tmpFileName));
						std::string* buff = new std::string(FBXTakeSearchObj.fnSearchForTake(marshal_as<string>(textBox1->Text))); //pass search request to function from textBox and assign results to string 
			            
						std::istringstream strmResultList(*buff);    //output line by line to textbox
			            while (std::getline(strmResultList, *buff)) {
			            textBox2->AppendText (marshal_as<String^>(*buff));  //use this shit to match std::string with CLI's System::String^
			            textBox2->AppendText ("\n");
						}
			            textBox2->AppendText ("\n");
			            delete buff;						
					}		
				}
				
		 }
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e)
		 {
			 
		 }
		 //-------------------- list takes in 1 file---------------------------------
private: System::Void btnListAllTakes_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			
			 	openFileDialog1->ShowDialog() ;
				std::string* buff = new std::string (marshal_as<string>(openFileDialog1->FileName));
			    FbxTakeNameList  FBXTakeSearchObj (buff);
			    *buff = 	FBXTakeSearchObj.fnOutputTakeNameList ();
			    
				textBox2->AppendText ("   - Takes:\n");
			    std::istringstream strmResultList(*buff);    //output line by line to textbox
			    while (std::getline(strmResultList, *buff)) {
			    textBox2->AppendText (marshal_as<String^>(*buff));  //use this shit to match std::string with CLI's System::String^
			    textBox2->AppendText ("\n");
			    }
			    textBox2->AppendText ("\n");
			    delete buff;


		 }
private: System::Void btnListTakesInFolder_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			//------------------------------------- list all takes in folder-----------------------
			 
			 folderBrowserDialog1->ShowDialog() ;
			 textBox2->Text = "";	
			 textBox2->AppendText ("    - Folder:\n");
			 textBox2->AppendText (folderBrowserDialog1->SelectedPath);
			 textBox2->AppendText ("\n");
			 textBox2->AppendText ("\n   - Take list in files: ");
			 textBox2->AppendText ("\n");
			 textBox2->AppendText ("\n");

			 String^ folder = folderBrowserDialog1->SelectedPath;  //  list all file in folder. part from MSDN
			 array<String^>^ file = Directory::GetFiles( folder ); //
	
			    for (int i=0; i<file->Length; i++)
				{    
					if (file[i]->Contains(".fbx"))
					{

						textBox2->AppendText(file[i]);
						textBox2->AppendText (":\n");
						System::String^ tmpFileName = file[i];						
						FbxTakeNameList  FBXTakeSearchObj (&marshal_as<string>(tmpFileName));
						std::string* buff = new std::string(FBXTakeSearchObj.fnOutputTakeNameList()); //output takes list to string 		            
						std::istringstream strmResultList(*buff);    //output line by line to textbox
			            while (std::getline(strmResultList, *buff)) {
			            textBox2->AppendText (marshal_as<String^>(*buff));  //use this shit to match std::string with CLI's System::String^
			            textBox2->AppendText ("\n");
						}
			            textBox2->AppendText ("\n");
			            delete buff;						
					}		
				}
			 
		 }
private: System::Void textBox2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			
		 }
};
}





