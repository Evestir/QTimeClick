#pragma once
#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>

namespace QTimeClick {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	static int TargetH = 0;
	static int TargetM = 0;
	static int TargetS = 0;

	static int TargetH_n = 12;
	static int TargetM_n = 0;
	static int TargetS_n = 0;

	static int pTtG;

	static bool starto;

	/// <summary>
	/// Summary for QuickTime
	/// </summary>
	public ref class QuickTime : public System::Windows::Forms::Form
	{
	public:
		static QuickTime^ TheInstance;
		QuickTime(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			TheInstance = this;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QuickTime()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ PanelDrag;
	private: System::Windows::Forms::TextBox^ HourPicker;
	private: System::Windows::Forms::TextBox^ MinutePicker;
	private: System::Windows::Forms::TextBox^ SecondPicker;

	private: System::Windows::Forms::PictureBox^ ButtonUp;
	private: System::Windows::Forms::PictureBox^ ButtonDown;

	public: System::Windows::Forms::Label^ Notification;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ wherelink;

	private: System::Windows::Forms::Label^ settingbtn;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuickTime::typeid));
			this->PanelDrag = (gcnew System::Windows::Forms::PictureBox());
			this->HourPicker = (gcnew System::Windows::Forms::TextBox());
			this->MinutePicker = (gcnew System::Windows::Forms::TextBox());
			this->SecondPicker = (gcnew System::Windows::Forms::TextBox());
			this->ButtonUp = (gcnew System::Windows::Forms::PictureBox());
			this->ButtonDown = (gcnew System::Windows::Forms::PictureBox());
			this->Notification = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->wherelink = (gcnew System::Windows::Forms::TextBox());
			this->settingbtn = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PanelDrag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ButtonUp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ButtonDown))->BeginInit();
			this->SuspendLayout();
			// 
			// PanelDrag
			// 
			this->PanelDrag->BackColor = System::Drawing::Color::Transparent;
			this->PanelDrag->Location = System::Drawing::Point(1, 1);
			this->PanelDrag->Name = L"PanelDrag";
			this->PanelDrag->Size = System::Drawing::Size(534, 30);
			this->PanelDrag->TabIndex = 0;
			this->PanelDrag->TabStop = false;
			this->PanelDrag->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &QuickTime::PanelDrag_MouseDown);
			this->PanelDrag->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &QuickTime::PanelDrag_MouseMove);
			this->PanelDrag->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &QuickTime::PanelDrag_MouseUp);
			// 
			// HourPicker
			// 
			this->HourPicker->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->HourPicker->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->HourPicker->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->HourPicker->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HourPicker->ForeColor = System::Drawing::Color::White;
			this->HourPicker->Location = System::Drawing::Point(175, 108);
			this->HourPicker->Name = L"HourPicker";
			this->HourPicker->ReadOnly = true;
			this->HourPicker->Size = System::Drawing::Size(76, 77);
			this->HourPicker->TabIndex = 1;
			this->HourPicker->Text = L"12";
			this->HourPicker->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MinutePicker
			// 
			this->MinutePicker->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->MinutePicker->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->MinutePicker->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MinutePicker->ForeColor = System::Drawing::Color::White;
			this->MinutePicker->Location = System::Drawing::Point(262, 108);
			this->MinutePicker->Name = L"MinutePicker";
			this->MinutePicker->ReadOnly = true;
			this->MinutePicker->Size = System::Drawing::Size(76, 77);
			this->MinutePicker->TabIndex = 2;
			this->MinutePicker->Text = L"00";
			this->MinutePicker->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// SecondPicker
			// 
			this->SecondPicker->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->SecondPicker->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->SecondPicker->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SecondPicker->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SecondPicker->ForeColor = System::Drawing::Color::White;
			this->SecondPicker->Location = System::Drawing::Point(349, 108);
			this->SecondPicker->MaxLength = 2;
			this->SecondPicker->Name = L"SecondPicker";
			this->SecondPicker->ReadOnly = true;
			this->SecondPicker->Size = System::Drawing::Size(76, 77);
			this->SecondPicker->TabIndex = 3;
			this->SecondPicker->Text = L"00";
			this->SecondPicker->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ButtonUp
			// 
			this->ButtonUp->BackColor = System::Drawing::Color::Transparent;
			this->ButtonUp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ButtonUp.BackgroundImage")));
			this->ButtonUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ButtonUp->Location = System::Drawing::Point(505, 131);
			this->ButtonUp->Name = L"ButtonUp";
			this->ButtonUp->Size = System::Drawing::Size(30, 20);
			this->ButtonUp->TabIndex = 5;
			this->ButtonUp->TabStop = false;
			this->ButtonUp->Click += gcnew System::EventHandler(this, &QuickTime::ButtonUp_Click);
			// 
			// ButtonDown
			// 
			this->ButtonDown->BackColor = System::Drawing::Color::Transparent;
			this->ButtonDown->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ButtonDown.BackgroundImage")));
			this->ButtonDown->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ButtonDown->Location = System::Drawing::Point(505, 147);
			this->ButtonDown->Name = L"ButtonDown";
			this->ButtonDown->Size = System::Drawing::Size(30, 20);
			this->ButtonDown->TabIndex = 6;
			this->ButtonDown->TabStop = false;
			this->ButtonDown->Click += gcnew System::EventHandler(this, &QuickTime::ButtonDown_Click);
			// 
			// Notification
			// 
			this->Notification->AutoSize = true;
			this->Notification->BackColor = System::Drawing::Color::Transparent;
			this->Notification->Font = (gcnew System::Drawing::Font(L"NanumSquare Neo Regular", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Notification->ForeColor = System::Drawing::Color::Silver;
			this->Notification->Location = System::Drawing::Point(33, 430);
			this->Notification->Name = L"Notification";
			this->Notification->Size = System::Drawing::Size(185, 14);
			this->Notification->TabIndex = 8;
			this->Notification->Text = L"Welcome to QuickTime v0.1.3";
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(240, 264);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 30);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Ping";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &QuickTime::label1_Click_1);
			this->label1->MouseEnter += gcnew System::EventHandler(this, &QuickTime::label1_MouseEnter);
			this->label1->MouseLeave += gcnew System::EventHandler(this, &QuickTime::label1_MouseLeave);
			// 
			// wherelink
			// 
			this->wherelink->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->wherelink->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->wherelink->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wherelink->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->wherelink->Location = System::Drawing::Point(175, 214);
			this->wherelink->Multiline = true;
			this->wherelink->Name = L"wherelink";
			this->wherelink->Size = System::Drawing::Size(250, 30);
			this->wherelink->TabIndex = 11;
			this->wherelink->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->wherelink->Enter += gcnew System::EventHandler(this, &QuickTime::wherelink_Enter);
			this->wherelink->Leave += gcnew System::EventHandler(this, &QuickTime::wherelink_Leave);
			// 
			// settingbtn
			// 
			this->settingbtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->settingbtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->settingbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->settingbtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->settingbtn->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->settingbtn->Location = System::Drawing::Point(240, 312);
			this->settingbtn->Name = L"settingbtn";
			this->settingbtn->Size = System::Drawing::Size(120, 30);
			this->settingbtn->TabIndex = 13;
			this->settingbtn->Text = L"Set Time";
			this->settingbtn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->settingbtn->Click += gcnew System::EventHandler(this, &QuickTime::settingbtn_Click);
			this->settingbtn->MouseEnter += gcnew System::EventHandler(this, &QuickTime::settingbtn_MouseEnter);
			this->settingbtn->MouseLeave += gcnew System::EventHandler(this, &QuickTime::settingbtn_MouseLeave);
			// 
			// QuickTime
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(600, 450);
			this->Controls->Add(this->settingbtn);
			this->Controls->Add(this->wherelink);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Notification);
			this->Controls->Add(this->ButtonDown);
			this->Controls->Add(this->ButtonUp);
			this->Controls->Add(this->SecondPicker);
			this->Controls->Add(this->MinutePicker);
			this->Controls->Add(this->HourPicker);
			this->Controls->Add(this->PanelDrag);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Ndot 55", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Location = System::Drawing::Point(240, 313);
			this->Name = L"QuickTime";
			this->Text = L"QuickTime";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PanelDrag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ButtonUp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ButtonDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool drag;
		System::Drawing::Point offset;

		private: System::Void PanelDrag_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			drag = true;
			offset.X = e->X;
			offset.Y = e->Y;
		}
		private: System::Void PanelDrag_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (drag) {
				System::Drawing::Point CSP = System::Windows::Forms::Control::PointToScreen(System::Drawing::Point(e->X, e->Y));
				Location = System::Drawing::Point(CSP.X - offset.X, CSP.Y - offset.Y);
			}
		}
		private: System::Void PanelDrag_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			drag = false;
		}
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		void getCtime() {
			TargetH_n = int::Parse(this->HourPicker->Text);
			TargetM_n = int::Parse(this->MinutePicker->Text);
			TargetS_n = int::Parse(this->SecondPicker->Text);
		}

		private: System::Void ButtonUp_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->HourPicker->ContainsFocus) {
				TargetH = int::Parse(this->HourPicker->Text);
				if (TargetH + 1 == 24) {
					this->HourPicker->Text = "0" + (0).ToString();
				}
				else {
					if (TargetH + 1 < 10) {
						this->HourPicker->Text = "0" + (TargetH + 1).ToString();
					}
					else {
						this->HourPicker->Text = (TargetH + 1).ToString();
					}
				}
				getCtime();
			}
			else if (this->MinutePicker->ContainsFocus) {
				TargetM = int::Parse(this->MinutePicker->Text);
				if (TargetM + 1 == 60) {
					this->MinutePicker->Text = "0" + (0).ToString();
				}
				else {
					if (TargetM + 1 < 10) {
						this->MinutePicker->Text = "0" + (TargetM + 1).ToString();
					}
					else {
						this->MinutePicker->Text = (TargetM + 1).ToString();
					}
				}
				getCtime();
			}
			else if (this->SecondPicker->ContainsFocus) {
				TargetS_n = int::Parse(this->SecondPicker->Text) + 1;
				TargetS = int::Parse(this->SecondPicker->Text);
				if (TargetS + 1 == 60) {
					this->SecondPicker->Text = "0" + (0).ToString();
				}
				else {
					if (TargetS + 1 < 10) {
						this->SecondPicker->Text = "0" + (TargetS + 1).ToString();
					}
					else {
						this->SecondPicker->Text = (TargetS + 1).ToString();
					}
				}
				getCtime();
			}
		}
		private: System::Void ButtonDown_Click(System::Object^ sender, System::EventArgs^ e) {
			TargetH_n = int::Parse(this->HourPicker->Text) - 1;
			TargetH = int::Parse(this->HourPicker->Text);
			if (this->HourPicker->ContainsFocus) {
				if (TargetH - 1 == -1) {
					this->HourPicker->Text = (23).ToString();
				}
				else {
					if (TargetH - 1 < 10) {
						this->HourPicker->Text = "0" + (TargetH - 1).ToString();
					}
					else {
						this->HourPicker->Text = (TargetH - 1).ToString();
					}
				}
				getCtime();
			}
			else if (this->MinutePicker->ContainsFocus) {
				TargetM_n = int::Parse(this->MinutePicker->Text) - 1;
				TargetM = int::Parse(this->MinutePicker->Text);
				if (TargetM - 1 == -1) {
					this->MinutePicker->Text = (59).ToString();
				}
				else {
					if (TargetM - 1 < 10) {
						this->MinutePicker->Text = "0" + (TargetM - 1).ToString();
					}
					else {
						this->MinutePicker->Text = (TargetM - 1).ToString();
					}
				}
				getCtime();
			}
			else if (this->SecondPicker->ContainsFocus) {
				TargetS_n = int::Parse(this->SecondPicker->Text) - 1;
				TargetS = int::Parse(this->SecondPicker->Text);
				if (TargetS - 1 == -1) {
					this->SecondPicker->Text = (59).ToString();
				}
				else {
					if (TargetS - 1 < 10) {
						this->SecondPicker->Text = "0" + (TargetS - 1).ToString();
					}
					else {
						this->SecondPicker->Text = (TargetS - 1).ToString();
					}
				}
				getCtime();
			}
		}
		private: System::Void setBtn_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			
		}
		private: System::Void setBtn_MouseLeave(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void setBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			
		}
		private: System::Void label1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			int n = 0;
			for (int i = 0; i < 150;) {
				n += 2;
				i += 15;
				this->label1->BackColor = System::Drawing::Color::FromArgb(255, 64 + i, 64 + i, 64 + i);
				this->label1->ForeColor = System::Drawing::Color::FromArgb(255, 255 - i, 255 - i, 255 - i);
				this->label1->Size = System::Drawing::Size(120 + n, 30);
				this->label1->Location = System::Drawing::Point(240 - n / 2, 264);
				this->label1->Refresh();
				Sleep(10);
			}
		}
		private: System::Void label1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			int n = 0;
			for (int i = 0; i < 150;) {
				i += 15;
				n += 2;
				this->label1->BackColor = System::Drawing::Color::FromArgb(255, 214 - i, 214 - i, 214 - i);
				this->label1->ForeColor = System::Drawing::Color::FromArgb(255, 105 + i, 105 + i, 105 + i);
				this->label1->Size = System::Drawing::Size(140 - n, 30);
				this->label1->Location = System::Drawing::Point(230 + n / 2, 264);
				this->Refresh();
			}
		}
		void RemoveWordFromLine(std::string& line, const std::string& word)
		{
			auto n = line.find(word);
			if (n != std::string::npos)
			{
				line.erase(n, word.length());
			}
		}

		bool pingAgetR(std::string where) {
			std::string a = "ping " + where + " > result.txt";
			if (system(a.c_str()) == 1) {
				MessageBox::Show(L"Request timed out. Please check the URL again.");
				return false;
			}
			std::ifstream file;

			file.open("result.txt");
			if (file.fail()) {
				MessageBox::Show(L"Could not open output file.");
				return false;
			}

			int cline = 0;
			std::string line;

			while (!file.eof()) {
				cline++;
				std::getline(file, line);
				if (cline == 11) {
					break;
				}
			}
			for (int n = 0; n < 2; n++) {
				line = line.substr(line.find(",") + 1);
			}

			RemoveWordFromLine(line, " Average = ");
			RemoveWordFromLine(line, "ms");
			/*freopen("CONOUT$", "w", stdout);
			std::cout << line << std::endl;*/

			pTtG = std::stoi(line);
			return true;
		}

		static std::string toss(System::String^ s)
		{
			// convert .NET System::String to std::string
			const char* cstr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			std::string sstr = cstr;
			Marshal::FreeHGlobal(System::IntPtr((void*)cstr));
			return sstr;
		}

		private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
			std::string a = toss(this->wherelink->Text);
			if (a == "") {
				MessageBox::Show(L"Please fill the url link.");
				return;
			}
			if (pingAgetR(toss(this->wherelink->Text)) == true) {
				this->Notification->Text = "Average ping to the target is " + pTtG.ToString() + "ms.";
			}
			else {
				this->Notification->Text = "Request timed out :/";
			}
		}

		private: System::Void settingbtn_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			int n = 0;
			for (int i = 0; i < 150;) {
				n += 2;
				i += 15;
				this->settingbtn->BackColor = System::Drawing::Color::FromArgb(255, 64 + i, 64 + i, 64 + i);
				this->settingbtn->ForeColor = System::Drawing::Color::FromArgb(255, 255 - i, 255 - i, 255 - i);
				this->settingbtn->Size = System::Drawing::Size(120 + n, 30);
				this->settingbtn->Location = System::Drawing::Point(240 - n / 2, 312);
				this->settingbtn->Refresh();
				Sleep(10);
			}

		}
		private: System::Void settingbtn_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			int n = 0;
			for (int i = 0; i < 150;) {
				i += 15;
				n += 2;
				this->settingbtn->BackColor = System::Drawing::Color::FromArgb(255, 214 - i, 214 - i, 214 - i);
				this->settingbtn->ForeColor = System::Drawing::Color::FromArgb(255, 105 + i, 105 + i, 105 + i);
				this->settingbtn->Size = System::Drawing::Size(140 - n, 30);
				this->settingbtn->Location = System::Drawing::Point(230 + n / 2, 312);
				this->Refresh();
			}
		}
		private: System::Void settingbtn_Click(System::Object^ sender, System::EventArgs^ e) {
			starto = true;
			this->Notification->Text = "Mouse will be clicked at " + (TargetH_n).ToString() + ":" + (TargetM_n).ToString() + ":" + (TargetS_n).ToString();
		}
		private: System::Void wherelink_Enter(System::Object^ sender, System::EventArgs^ e) {
			int a = 0;
			for (int i = 0; i < 15;) {
				i += 1;
				a += 3;
				this->wherelink->BackColor = System::Drawing::Color::FromArgb(255, 41 + i*8, 41 + i*8, 41 + i*8);
				this->wherelink->Size = System::Drawing::Size(250 + a, 30);
				this->wherelink->Location = System::Drawing::Point(175 - a / 2, 214);
				this->wherelink->Refresh();
				Sleep(10);
			}
		}
		private: System::Void wherelink_Leave(System::Object^ sender, System::EventArgs^ e) {
			int a = 0;
			for (int i = 0; i < 15;) {
				i += 1;
				a += 3;
				this->wherelink->BackColor = System::Drawing::Color::FromArgb(255, 161 - i*8, 161 - i*8, 161 - i*8);
				if (a < 50) {
					this->wherelink->Size = System::Drawing::Size(295 - a, 30);
					this->wherelink->Location = System::Drawing::Point(154 + a / 2, 214);
				}
				else {
					this->wherelink->Location = System::Drawing::Point(175, 214);
				}
				this->Refresh();
			}
		}
	};
}
