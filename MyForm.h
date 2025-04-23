#pragma once

#include "Dot.h"
#include"Line.h"
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <algorithm>

namespace GraphicEngine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	std::vector<Dot*> Dots;
	std::vector<Line*> Lines;

	std::set<Dot> setik;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picture;
	private: System::Windows::Forms::DataGridView^ GridDots;


	private: System::Windows::Forms::DataGridView^ GridLines;


	private: System::Windows::Forms::Button^ ClearButton;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::TextBox^ TextBoxNameDot;
	private: System::Windows::Forms::TextBox^ TextBoxNamePointToMove;
	private: System::Windows::Forms::Button^ ButtonMovePoint;
	private: System::Windows::Forms::Button^ ColorButton;
	private: System::Windows::Forms::TextBox^ TextBoxDxPointToMove;
	private: System::Windows::Forms::Label^ LabelCreateLine;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ TextBoxCreateLine1;
	private: System::Windows::Forms::TextBox^ TextBoxDyPointToMove;
	private: System::Windows::Forms::TextBox^ TextBoxCreateLine2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ ButtonCreateLine;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ LabelMovePoint;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ AddPlexButton;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ ReadPlexButton;
	private: System::Windows::Forms::Button^ savePlexButtom;
	private: System::Windows::Forms::RadioButton^ DotButton;
	private: System::Windows::Forms::RadioButton^ LineButton;
	private: System::Windows::Forms::TextBox^ TestText;


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generatingd code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->GridDots = (gcnew System::Windows::Forms::DataGridView());
			this->GridLines = (gcnew System::Windows::Forms::DataGridView());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->TextBoxNameDot = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxNamePointToMove = (gcnew System::Windows::Forms::TextBox());
			this->ButtonMovePoint = (gcnew System::Windows::Forms::Button());
			this->ColorButton = (gcnew System::Windows::Forms::Button());
			this->TextBoxDxPointToMove = (gcnew System::Windows::Forms::TextBox());
			this->LabelCreateLine = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TextBoxCreateLine1 = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxDyPointToMove = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxCreateLine2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ButtonCreateLine = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->LabelMovePoint = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->AddPlexButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ReadPlexButton = (gcnew System::Windows::Forms::Button());
			this->savePlexButtom = (gcnew System::Windows::Forms::Button());
			this->DotButton = (gcnew System::Windows::Forms::RadioButton());
			this->LineButton = (gcnew System::Windows::Forms::RadioButton());
			this->TestText = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridDots))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridLines))->BeginInit();
			this->SuspendLayout();
			// 
			// picture
			// 
			this->picture->BackColor = System::Drawing::Color::White;
			this->picture->Location = System::Drawing::Point(24, 111);
			this->picture->Margin = System::Windows::Forms::Padding(6);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(1000, 961);
			this->picture->TabIndex = 0;
			this->picture->TabStop = false;
			this->picture->Click += gcnew System::EventHandler(this, &MyForm::picture_Click);
			this->picture->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pict_MouseDown);
			// 
			// GridDots
			// 
			this->GridDots->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->GridDots->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->GridDots->BackgroundColor = System::Drawing::Color::Thistle;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->GridDots->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->GridDots->ColumnHeadersHeight = 29;
			this->GridDots->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"HoloLens MDL2 Assets", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Navy;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->GridDots->DefaultCellStyle = dataGridViewCellStyle2;
			this->GridDots->Location = System::Drawing::Point(1066, 41);
			this->GridDots->Margin = System::Windows::Forms::Padding(6);
			this->GridDots->Name = L"GridDots";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Navy;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->GridDots->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->GridDots->RowHeadersVisible = false;
			this->GridDots->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->GridDots->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->GridDots->Size = System::Drawing::Size(933, 961);
			this->GridDots->TabIndex = 1;
			// 
			// GridLines
			// 
			this->GridLines->ColumnHeadersHeight = 29;
			this->GridLines->Location = System::Drawing::Point(0, 0);
			this->GridLines->Name = L"GridLines";
			this->GridLines->RowHeadersWidth = 51;
			this->GridLines->Size = System::Drawing::Size(240, 150);
			this->GridLines->TabIndex = 0;
			// 
			// ClearButton
			// 
			this->ClearButton->Location = System::Drawing::Point(0, 0);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(75, 23);
			this->ClearButton->TabIndex = 0;
			// 
			// TextBoxNameDot
			// 
			this->TextBoxNameDot->Location = System::Drawing::Point(0, 0);
			this->TextBoxNameDot->Name = L"TextBoxNameDot";
			this->TextBoxNameDot->Size = System::Drawing::Size(100, 31);
			this->TextBoxNameDot->TabIndex = 0;
			// 
			// TextBoxNamePointToMove
			// 
			this->TextBoxNamePointToMove->Location = System::Drawing::Point(0, 0);
			this->TextBoxNamePointToMove->Name = L"TextBoxNamePointToMove";
			this->TextBoxNamePointToMove->Size = System::Drawing::Size(100, 31);
			this->TextBoxNamePointToMove->TabIndex = 0;
			// 
			// ButtonMovePoint
			// 
			this->ButtonMovePoint->Location = System::Drawing::Point(0, 0);
			this->ButtonMovePoint->Name = L"ButtonMovePoint";
			this->ButtonMovePoint->Size = System::Drawing::Size(75, 23);
			this->ButtonMovePoint->TabIndex = 0;
			// 
			// ColorButton
			// 
			this->ColorButton->Location = System::Drawing::Point(0, 0);
			this->ColorButton->Name = L"ColorButton";
			this->ColorButton->Size = System::Drawing::Size(75, 23);
			this->ColorButton->TabIndex = 0;
			// 
			// TextBoxDxPointToMove
			// 
			this->TextBoxDxPointToMove->Location = System::Drawing::Point(0, 0);
			this->TextBoxDxPointToMove->Name = L"TextBoxDxPointToMove";
			this->TextBoxDxPointToMove->Size = System::Drawing::Size(100, 31);
			this->TextBoxDxPointToMove->TabIndex = 0;
			// 
			// LabelCreateLine
			// 
			this->LabelCreateLine->Location = System::Drawing::Point(0, 0);
			this->LabelCreateLine->Name = L"LabelCreateLine";
			this->LabelCreateLine->Size = System::Drawing::Size(100, 23);
			this->LabelCreateLine->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 0;
			// 
			// TextBoxCreateLine1
			// 
			this->TextBoxCreateLine1->Location = System::Drawing::Point(0, 0);
			this->TextBoxCreateLine1->Name = L"TextBoxCreateLine1";
			this->TextBoxCreateLine1->Size = System::Drawing::Size(100, 31);
			this->TextBoxCreateLine1->TabIndex = 0;
			// 
			// TextBoxDyPointToMove
			// 
			this->TextBoxDyPointToMove->Location = System::Drawing::Point(0, 0);
			this->TextBoxDyPointToMove->Name = L"TextBoxDyPointToMove";
			this->TextBoxDyPointToMove->Size = System::Drawing::Size(100, 31);
			this->TextBoxDyPointToMove->TabIndex = 0;
			// 
			// TextBoxCreateLine2
			// 
			this->TextBoxCreateLine2->Location = System::Drawing::Point(0, 0);
			this->TextBoxCreateLine2->Name = L"TextBoxCreateLine2";
			this->TextBoxCreateLine2->Size = System::Drawing::Size(100, 31);
			this->TextBoxCreateLine2->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 0;
			// 
			// ButtonCreateLine
			// 
			this->ButtonCreateLine->Location = System::Drawing::Point(0, 0);
			this->ButtonCreateLine->Name = L"ButtonCreateLine";
			this->ButtonCreateLine->Size = System::Drawing::Size(75, 23);
			this->ButtonCreateLine->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 0;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(0, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 23);
			this->label6->TabIndex = 0;
			// 
			// LabelMovePoint
			// 
			this->LabelMovePoint->Location = System::Drawing::Point(0, 0);
			this->LabelMovePoint->Name = L"LabelMovePoint";
			this->LabelMovePoint->Size = System::Drawing::Size(100, 23);
			this->LabelMovePoint->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(0, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 23);
			this->label5->TabIndex = 0;
			// 
			// AddPlexButton
			// 
			this->AddPlexButton->Location = System::Drawing::Point(0, 0);
			this->AddPlexButton->Name = L"AddPlexButton";
			this->AddPlexButton->Size = System::Drawing::Size(75, 23);
			this->AddPlexButton->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(0, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 23);
			this->label4->TabIndex = 0;
			// 
			// ReadPlexButton
			// 
			this->ReadPlexButton->Location = System::Drawing::Point(0, 0);
			this->ReadPlexButton->Name = L"ReadPlexButton";
			this->ReadPlexButton->Size = System::Drawing::Size(75, 23);
			this->ReadPlexButton->TabIndex = 0;
			// 
			// savePlexButtom
			// 
			this->savePlexButtom->Location = System::Drawing::Point(0, 0);
			this->savePlexButtom->Name = L"savePlexButtom";
			this->savePlexButtom->Size = System::Drawing::Size(75, 23);
			this->savePlexButtom->TabIndex = 0;
			// 
			// DotButton
			// 
			this->DotButton->AutoSize = true;
			this->DotButton->Checked = true;
			this->DotButton->Location = System::Drawing::Point(104, 63);
			this->DotButton->Name = L"DotButton";
			this->DotButton->Size = System::Drawing::Size(76, 29);
			this->DotButton->TabIndex = 2;
			this->DotButton->TabStop = true;
			this->DotButton->Text = L"Dot";
			this->DotButton->UseVisualStyleBackColor = true;
			this->DotButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::changeToDot);
			// 
			// LineButton
			// 
			this->LineButton->AutoSize = true;
			this->LineButton->Location = System::Drawing::Point(362, 63);
			this->LineButton->Name = L"LineButton";
			this->LineButton->Size = System::Drawing::Size(84, 29);
			this->LineButton->TabIndex = 3;
			this->LineButton->Text = L"Line";
			this->LineButton->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->LineButton->UseVisualStyleBackColor = true;
			this->LineButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::changeToLine);
			// 
			// TestText
			// 
			this->TestText->Location = System::Drawing::Point(648, 60);
			this->TestText->Name = L"TestText";
			this->TestText->Size = System::Drawing::Size(338, 31);
			this->TestText->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::DarkMagenta;
			this->ClientSize = System::Drawing::Size(2140, 1166);
			this->Controls->Add(this->TestText);
			this->Controls->Add(this->LineButton);
			this->Controls->Add(this->DotButton);
			this->Controls->Add(this->GridDots);
			this->Controls->Add(this->picture);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridDots))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridLines))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Graphics^ g;
		Bitmap^ Image;
		SolidBrush^ Brush;
		int DotName = -1;
		int COLOR = 2550255;
		int m_prevX, m_prevY;
		int state = 0;
		int lineModClickCount = 0;
		Dot* first = nullptr;
		Dot* second = nullptr;

		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			Image = gcnew Bitmap(picture->Width, picture->Height);
			g = Graphics::FromImage(Image);
			picture->Image = Image;
		}

		void MarshalString(String^ s, std::string& os)
		{
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void PrintDotsDataGrid()
		{
			GridDots->RowCount = Dots.size();
			GridDots->ColumnCount = 6;
			GridDots->Columns[0]->HeaderCell->Value = "Name";
			GridDots->Columns[1]->HeaderCell->Value = "X";
			GridDots->Columns[2]->HeaderCell->Value = "Y";
			GridDots->Columns[3]->HeaderCell->Value = "Color";
			GridDots->Columns[4]->HeaderCell->Value = "Radius";
			GridDots->Columns[5]->HeaderCell->Value = "Boldness";

			for (int i = 0; i < Dots.size(); i++)
			{
				GridDots->Rows[i]->Cells[1]->Value = System::Convert::ToString(Dots[i]->getX());
				GridDots->Rows[i]->Cells[2]->Value = System::Convert::ToString(Dots[i]->getY());
				GridDots->Rows[i]->Cells[3]->Value = System::Convert::ToString(Dots[i]->getColor());
				GridDots->Rows[i]->Cells[4]->Value = System::Convert::ToString(Dots[i]->getRadius());
				GridDots->Rows[i]->Cells[5]->Value = System::Convert::ToString(Dots[i]->getWidth());
			}
		}

		std::string TranslateTo26(int x)
		{
			std::string ans;
			while (x)
			{
				ans += char(x % 26 + 'A');
				x /= 26;
			}
			std::reverse(ans.begin(), ans.end());
			if (ans.size() == 0)
			{
				ans += 'A';
			}
			return ans;
		}

		std::string GeneratingNewName()
		{
			return TranslateTo26(++DotName);
		}
		System::Void pict_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

			//groupBox1->Visible = true;
			int X = e->X;
			int Y = e->Y;
			int index = -1;
			
			for (int i = 0; i <  Dots.size(); i++) {
				if(Dots[i]->IsFigure(X, Y)) {
					index = i;
					break;
				}
			}
			if (e->Button == System::Windows::Forms::MouseButtons::Left && state==0 && index ==-1)
			{
				Image = gcnew Bitmap(picture->Image);
				std::string name = GeneratingNewName();

				Dots.push_back(new Dot(name, X, Y));
				Dots.back()->setColor(COLOR);
				PrintDotsDataGrid();
				DrawDots();
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Left && state == 1 && lineModClickCount % 2 == 0)
			{
				if (index == -1) {
					Image = gcnew Bitmap(picture->Image);
					std::string name = GeneratingNewName();

					Dots.push_back(new Dot(name, X, Y));
					Dots.back()->setColor(COLOR);
					PrintDotsDataGrid();
					DrawDots();
					first = Dots.back();
				}
				else {
					first = Dots[index];
				}
				lineModClickCount++;
			}
			else if (e->Button == System::Windows::Forms::MouseButtons::Left && state == 1 && lineModClickCount % 2 == 1) {
				
				if (index == -1) {
					Image = gcnew Bitmap(picture->Image);
					std::string name = GeneratingNewName();

					Dots.push_back(new Dot(name, X, Y));
					Dots.back()->setColor(COLOR);
					PrintDotsDataGrid();
					DrawDots();
					second = Dots.back();
				}
				else {
					second = Dots[index];
				}

				Lines.push_back(new Line(first, second));
				first = nullptr;
				second = nullptr;
				Lines.back()->setColor(COLOR);
				DrawLines();
				lineModClickCount++;
			}
		}



		void DrawDots()
		{
			for (int i = 0; i < Dots.size(); i++)
			{
				delete g;
				g = Graphics::FromImage(Image);
				picture->Image = Image;
				Dots[i]->setColor(COLOR);
				Dots[i]->Draw(g);
				picture->Refresh();
				picture->Invalidate();
			}
		}
		void DrawLines() {
			for (int i = 0; i < Lines.size(); i++)
			{
				delete g;
				g = Graphics::FromImage(Image);
				picture->Image = Image;
				Lines[i]->setColor(COLOR);
				Lines[i]->Draw(g);
				picture->Refresh();
				picture->Invalidate();
			}
		}
		

	private: System::Void picture_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void changeToDot(System::Object^ sender, System::EventArgs^ e) {
	state = 0; //dot==0 state
	lineModClickCount = 0;
	TestText->Text = state.ToString();
}
private: System::Void changeToLine(System::Object^ sender, System::EventArgs^ e) {
	state = 1;
	TestText->Text = state.ToString();
}
};
}
