#include <iostream>
#include <vector>
#include <dos.h>
#include <time.h>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <time.h>

using namespace std;
using namespace System;

#pragma once
#define S 100
#define NAME_SIZE 8
#define SEC_SIZE 128
#define FILE_INFO 32
#define COUNT_SEC 100
#define ROOT_SEC 8
bool permition;
int fill_sectors = 0;
char key[10] = "./\[]:;|=,";
string filling_text = "AABBCCEE ";

struct file
{
	string name;
	bool type;
	int size;
	int first_sector;
	int count_sectors;
	string text;
	vector<file> files;
	string time_create;
	string time_change;
}root, *directory = &root;

vector<file*> back_path;

void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

file add_file(string name, bool type, int size, int count_sectors ,int first_sector, file *directory)
{
	time_t t = time(NULL);
	string time = ctime(&t);
	file new_file;
	new_file.name = name;
	new_file.type = type;
	new_file.size = size; 
	new_file.time_create = time.substr(11, 8);
	new_file.time_change = new_file.time_create;

	if (type)
	{
		new_file.first_sector = first_sector;
		new_file.count_sectors = count_sectors;

		(*directory).files.push_back(new_file);
	}
	else
	{
		new_file.name += ".TXT";
		if (size == 0)
		{
			new_file.first_sector = -1;
			new_file.count_sectors = count_sectors;
		}
		else
		{
			new_file.first_sector = first_sector;
			new_file.count_sectors = count_sectors;

			for (int i = 0; i < size; i += 9)
			{
				if (i + 9 < size)
				new_file.text += filling_text;
				else
					new_file.text += filling_text.substr(0, size - new_file.text.size());
			}
		}
		
		(*directory).files.push_back(new_file);
	}
	return new_file;
}

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  Records_table;
	private: System::Windows::Forms::DataGridView^  FAT_table;
	protected:

	protected:














	private: System::Windows::Forms::Button^  open_button;


	private: System::Windows::Forms::Label^  file_path;


	private: System::Windows::Forms::TextBox^  enter_name;


	private: System::Windows::Forms::NumericUpDown^  enter_size;

	private: System::Windows::Forms::Button^  create_button;

	private: System::Windows::Forms::Label^  label_name;
	private: System::Windows::Forms::Label^  label_type;
	private: System::Windows::Forms::Label^  label_size;
	private: System::Windows::Forms::Button^  OK_button;
	private: System::Windows::Forms::Button^  Cancel_button;






	private: System::Windows::Forms::RadioButton^  choose_file;
	private: System::Windows::Forms::Panel^  choose_type;


	private: System::Windows::Forms::RadioButton^  choose_catalog;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::RichTextBox^  file_text;
	private: System::Windows::Forms::Button^  change_file_text_button;













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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->Records_table = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FAT_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->open_button = (gcnew System::Windows::Forms::Button());
			this->file_path = (gcnew System::Windows::Forms::Label());
			this->enter_name = (gcnew System::Windows::Forms::TextBox());
			this->enter_size = (gcnew System::Windows::Forms::NumericUpDown());
			this->create_button = (gcnew System::Windows::Forms::Button());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->label_type = (gcnew System::Windows::Forms::Label());
			this->label_size = (gcnew System::Windows::Forms::Label());
			this->OK_button = (gcnew System::Windows::Forms::Button());
			this->Cancel_button = (gcnew System::Windows::Forms::Button());
			this->choose_file = (gcnew System::Windows::Forms::RadioButton());
			this->choose_type = (gcnew System::Windows::Forms::Panel());
			this->choose_catalog = (gcnew System::Windows::Forms::RadioButton());
			this->file_text = (gcnew System::Windows::Forms::RichTextBox());
			this->change_file_text_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Records_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FAT_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enter_size))->BeginInit();
			this->choose_type->SuspendLayout();
			this->SuspendLayout();
			// 
			// Records_table
			// 
			this->Records_table->AllowUserToAddRows = false;
			this->Records_table->AllowUserToDeleteRows = false;
			this->Records_table->AllowUserToResizeColumns = false;
			this->Records_table->AllowUserToResizeRows = false;
			this->Records_table->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Records_table->BackgroundColor = System::Drawing::Color::FloralWhite;
			this->Records_table->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->Records_table->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Records_table->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->Records_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Records_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn1,
					this->Column3, this->Column5, this->dataGridViewTextBoxColumn2, this->Column4, this->Column6
			});
			this->Records_table->Location = System::Drawing::Point(558, 0);
			this->Records_table->Name = L"Records_table";
			this->Records_table->RowHeadersVisible = false;
			this->Records_table->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->Records_table->Size = System::Drawing::Size(603, 330);
			this->Records_table->TabIndex = 3;
			this->Records_table->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Records_table_CellClick);
			this->Records_table->SelectionChanged += gcnew System::EventHandler(this, &MyForm::Records_table_SelectionChanged);
			// 
			// dataGridViewTextBoxColumn1
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewTextBoxColumn1->Frozen = true;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Имя";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column3
			// 
			this->Column3->Frozen = true;
			this->Column3->HeaderText = L"Тип";
			this->Column3->Name = L"Column3";
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column5
			// 
			this->Column5->Frozen = true;
			this->Column5->HeaderText = L"Размер(бaйт)";
			this->Column5->Name = L"Column5";
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// dataGridViewTextBoxColumn2
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->dataGridViewTextBoxColumn2->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewTextBoxColumn2->Frozen = true;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Начальный сектор";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column4
			// 
			this->Column4->Frozen = true;
			this->Column4->HeaderText = L"Время создания";
			this->Column4->Name = L"Column4";
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column6
			// 
			this->Column6->Frozen = true;
			this->Column6->HeaderText = L"Время изменения";
			this->Column6->Name = L"Column6";
			this->Column6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// FAT_table
			// 
			this->FAT_table->AllowUserToDeleteRows = false;
			this->FAT_table->AllowUserToResizeColumns = false;
			this->FAT_table->AllowUserToResizeRows = false;
			this->FAT_table->BackgroundColor = System::Drawing::Color::FloralWhite;
			this->FAT_table->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->FAT_table->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->FAT_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->FAT_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Column1, this->Column2 });
			this->FAT_table->Dock = System::Windows::Forms::DockStyle::Left;
			this->FAT_table->Location = System::Drawing::Point(0, 0);
			this->FAT_table->Name = L"FAT_table";
			this->FAT_table->RowHeadersVisible = false;
			this->FAT_table->Size = System::Drawing::Size(221, 617);
			this->FAT_table->TabIndex = 2;
			this->FAT_table->SelectionChanged += gcnew System::EventHandler(this, &MyForm::FAT_table_SelectionChanged);
			// 
			// Column1
			// 
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->DefaultCellStyle = dataGridViewCellStyle5;
			this->Column1->Frozen = true;
			this->Column1->HeaderText = L"Номер сектора";
			this->Column1->Name = L"Column1";
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column2
			// 
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->Column2->DefaultCellStyle = dataGridViewCellStyle6;
			this->Column2->Frozen = true;
			this->Column2->HeaderText = L"Следующий сектор";
			this->Column2->Name = L"Column2";
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// open_button
			// 
			this->open_button->Enabled = false;
			this->open_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->open_button->Location = System::Drawing::Point(324, 81);
			this->open_button->Name = L"open_button";
			this->open_button->Size = System::Drawing::Size(93, 27);
			this->open_button->TabIndex = 5;
			this->open_button->Text = L"Открыть";
			this->open_button->UseVisualStyleBackColor = true;
			this->open_button->Click += gcnew System::EventHandler(this, &MyForm::open_button_Click);
			// 
			// file_path
			// 
			this->file_path->Enabled = false;
			this->file_path->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->file_path->ForeColor = System::Drawing::Color::Black;
			this->file_path->Location = System::Drawing::Point(221, 0);
			this->file_path->Name = L"file_path";
			this->file_path->Size = System::Drawing::Size(338, 40);
			this->file_path->TabIndex = 7;
			this->file_path->Text = L"root\\";
			// 
			// enter_name
			// 
			this->enter_name->Location = System::Drawing::Point(778, 373);
			this->enter_name->Name = L"enter_name";
			this->enter_name->Size = System::Drawing::Size(100, 20);
			this->enter_name->TabIndex = 8;
			this->enter_name->Visible = false;
			// 
			// enter_size
			// 
			this->enter_size->Location = System::Drawing::Point(995, 374);
			this->enter_size->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12800, 0, 0, 0 });
			this->enter_size->Name = L"enter_size";
			this->enter_size->Size = System::Drawing::Size(120, 20);
			this->enter_size->TabIndex = 10;
			this->enter_size->Visible = false;
			// 
			// create_button
			// 
			this->create_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->create_button->Location = System::Drawing::Point(324, 147);
			this->create_button->Name = L"create_button";
			this->create_button->Size = System::Drawing::Size(93, 27);
			this->create_button->TabIndex = 12;
			this->create_button->Text = L"Создать";
			this->create_button->UseVisualStyleBackColor = true;
			this->create_button->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name->Location = System::Drawing::Point(810, 347);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(34, 16);
			this->label_name->TabIndex = 13;
			this->label_name->Text = L"Имя";
			this->label_name->Visible = false;
			// 
			// label_type
			// 
			this->label_type->AutoSize = true;
			this->label_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_type->Location = System::Drawing::Point(921, 347);
			this->label_type->Name = L"label_type";
			this->label_type->Size = System::Drawing::Size(33, 16);
			this->label_type->TabIndex = 14;
			this->label_type->Text = L"Тип";
			this->label_type->Visible = false;
			// 
			// label_size
			// 
			this->label_size->AutoSize = true;
			this->label_size->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_size->Location = System::Drawing::Point(1005, 347);
			this->label_size->Name = L"label_size";
			this->label_size->Size = System::Drawing::Size(97, 16);
			this->label_size->TabIndex = 15;
			this->label_size->Text = L"Размер(байт)";
			this->label_size->Visible = false;
			// 
			// OK_button
			// 
			this->OK_button->BackColor = System::Drawing::Color::LimeGreen;
			this->OK_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OK_button->Location = System::Drawing::Point(1075, 436);
			this->OK_button->Name = L"OK_button";
			this->OK_button->Size = System::Drawing::Size(75, 23);
			this->OK_button->TabIndex = 16;
			this->OK_button->Text = L"ОК";
			this->OK_button->UseVisualStyleBackColor = false;
			this->OK_button->Visible = false;
			this->OK_button->Click += gcnew System::EventHandler(this, &MyForm::OK_button_Click);
			// 
			// Cancel_button
			// 
			this->Cancel_button->BackColor = System::Drawing::Color::LightCoral;
			this->Cancel_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Cancel_button->Location = System::Drawing::Point(778, 436);
			this->Cancel_button->Name = L"Cancel_button";
			this->Cancel_button->Size = System::Drawing::Size(75, 23);
			this->Cancel_button->TabIndex = 17;
			this->Cancel_button->Text = L"Отмена";
			this->Cancel_button->UseVisualStyleBackColor = false;
			this->Cancel_button->Visible = false;
			this->Cancel_button->Click += gcnew System::EventHandler(this, &MyForm::Cancel_button_Click);
			// 
			// choose_file
			// 
			this->choose_file->AutoSize = true;
			this->choose_file->Location = System::Drawing::Point(3, 6);
			this->choose_file->Name = L"choose_file";
			this->choose_file->Size = System::Drawing::Size(41, 17);
			this->choose_file->TabIndex = 18;
			this->choose_file->TabStop = true;
			this->choose_file->Text = L"File";
			this->choose_file->UseVisualStyleBackColor = true;
			this->choose_file->CheckedChanged += gcnew System::EventHandler(this, &MyForm::choose_file_CheckedChanged);
			// 
			// choose_type
			// 
			this->choose_type->Controls->Add(this->choose_catalog);
			this->choose_type->Controls->Add(this->choose_file);
			this->choose_type->Location = System::Drawing::Point(900, 373);
			this->choose_type->Name = L"choose_type";
			this->choose_type->Size = System::Drawing::Size(74, 52);
			this->choose_type->TabIndex = 19;
			this->choose_type->Visible = false;
			// 
			// choose_catalog
			// 
			this->choose_catalog->AutoSize = true;
			this->choose_catalog->Location = System::Drawing::Point(3, 29);
			this->choose_catalog->Name = L"choose_catalog";
			this->choose_catalog->Size = System::Drawing::Size(61, 17);
			this->choose_catalog->TabIndex = 19;
			this->choose_catalog->TabStop = true;
			this->choose_catalog->Text = L"Catalog";
			this->choose_catalog->UseVisualStyleBackColor = true;
			// 
			// file_text
			// 
			this->file_text->BackColor = System::Drawing::SystemColors::Window;
			this->file_text->Location = System::Drawing::Point(227, 336);
			this->file_text->Name = L"file_text";
			this->file_text->ReadOnly = true;
			this->file_text->Size = System::Drawing::Size(480, 255);
			this->file_text->TabIndex = 20;
			this->file_text->Text = L"";
			this->file_text->TextChanged += gcnew System::EventHandler(this, &MyForm::file_text_TextChanged);
			// 
			// change_file_text_button
			// 
			this->change_file_text_button->Enabled = false;
			this->change_file_text_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->change_file_text_button->Location = System::Drawing::Point(442, 594);
			this->change_file_text_button->Name = L"change_file_text_button";
			this->change_file_text_button->Size = System::Drawing::Size(100, 23);
			this->change_file_text_button->TabIndex = 21;
			this->change_file_text_button->Text = L"Изменить";
			this->change_file_text_button->UseVisualStyleBackColor = true;
			this->change_file_text_button->Click += gcnew System::EventHandler(this, &MyForm::change_file_text_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1162, 617);
			this->Controls->Add(this->change_file_text_button);
			this->Controls->Add(this->file_text);
			this->Controls->Add(this->choose_type);
			this->Controls->Add(this->Cancel_button);
			this->Controls->Add(this->OK_button);
			this->Controls->Add(this->label_size);
			this->Controls->Add(this->label_type);
			this->Controls->Add(this->label_name);
			this->Controls->Add(this->create_button);
			this->Controls->Add(this->enter_size);
			this->Controls->Add(this->enter_name);
			this->Controls->Add(this->file_path);
			this->Controls->Add(this->open_button);
			this->Controls->Add(this->Records_table);
			this->Controls->Add(this->FAT_table);
			this->ForeColor = System::Drawing::SystemColors::WindowText;
			this->Name = L"MyForm";
			this->Text = L"Модель файловой системы FAT-12";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Records_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FAT_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enter_size))->EndInit();
			this->choose_type->ResumeLayout(false);
			this->choose_type->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void create_button_Click(System::Object^  sender, System::EventArgs^  e) {
			//Открыть меню добавления файла (при этом доступ к таблице запрещён)
			 label_name->Visible = true;
			 label_type->Visible = true;
			 enter_name->Visible = true;
			 choose_type->Visible = true;
			 Cancel_button->Visible = true;
			 OK_button->Visible = true;

			 create_button->Enabled = false;
			 open_button->Enabled = false;

			 Records_table->ClearSelection();
			 Records_table->Enabled = false;
			 FAT_table->ClearSelection();
}

private: System::Void Cancel_button_Click(System::Object^  sender, System::EventArgs^  e) {
			 //скрыть меню добавления файла(таблица становится доступной)
			 label_name->Visible = false;
			 label_type->Visible = false;
			 enter_name->Visible = false;
			 choose_type->Visible = false;
			 Cancel_button->Visible = false;
			 OK_button->Visible = false;
			 label_size->Visible = false;
			 enter_size->Visible = false;
			 choose_file->Checked = false;
			 choose_catalog->Checked = false;

			 enter_name->Text = "";
			 enter_size->Value = 0;

			 create_button->Enabled = true;

			 Records_table->Enabled = true;
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			//При загрузке формы индексируем логические секторы в FAT таблице.
			 for (int i = 0; i < S; i++)
			 {
				 FAT_table->Rows->Add();
				 FAT_table->Rows[i]->Cells[0]->Value = i;
				 FAT_table->Rows[i]->Cells[1]->Value = -2;
				 FAT_table->Rows[i]->ReadOnly = true;
			 }
			 FAT_table->AllowUserToAddRows = false;

			 //Даём характеристику корневой директории
			 string time = __TIME__;
			 root.name = "root";
			 root.type = 1;
			 root.size = 0;
			 root.first_sector = -1;
			 root.count_sectors = 2;
			 root.time_create = time.substr(0, 5);
			 root.time_change = time.substr(0, 5);

			 FAT_table->ClearSelection();
			 enter_size->Maximum = COUNT_SEC * SEC_SIZE;
}

private: System::Void choose_file_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			//выбор типа файла(если это не каталог, то открываем возможность ввода размера файла)
			 if (choose_file->Checked)
			 {
				 label_size->Visible = true;
				 enter_size->Visible = true;
			 }
			 else
			 {
				 label_size->Visible = false;
				 enter_size->Visible = false;
				 enter_size->Value = 0;
			 }
}

private: System::Void FAT_table_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {
			//Отключаем возможность выделять ячейки в FAT таблице
			 if (permition)
				 FAT_table->ClearSelection();
}

private: System::Void OK_button_Click(System::Object^  sender, System::EventArgs^  e) {
			//Добавление файла со всеми проверками
			 if (enter_name->TextLength == 0)
			 {
				 MessageBox::Show("Имя должно состоять хотя бы из одного символа", "Ошибка", MessageBoxButtons::OK);
				 return;
			 }

			 if (enter_name->TextLength > 8)
			 {
				 MessageBox::Show("Длина имени не должна превышать 8 символов", "Ошибка", MessageBoxButtons::OK);
				 return;
			 }
			 string file_name;
			 MarshalString(enter_name->Text, file_name);

			 if (file_name.find_first_of("./\[]:;|=,") != string::npos)
			 {
				 MessageBox::Show("Недопустимые символы в имени файла", "Ошибка", MessageBoxButtons::OK);
				 return;
			 }

			 //Преобразуем имя файла к виду, в котором оно будет храниться в памяти
			 size_t pos = 0;
			 
			 while ((pos = file_name.find(" ", pos)) != string::npos) 
				 file_name.replace(pos, 1, "");

			 std::transform(file_name.begin(), file_name.end(), file_name.begin(), toupper);

			 int j = file_name.size();
			 for (int i = 0; i < NAME_SIZE - j; i++)
			 {
				 file_name += "_";
			 }

			 //Проверяем, если файл с таким именем в директории, куда мы хотим добавить файл
			 for (int i = 0; i < (*directory).files.size(); i++)
			 {
				 if (file_name == (*directory).files[i].name.substr(0, NAME_SIZE))
				 {
					 MessageBox::Show("Файл с таким именем уже есть в данной директории", "Ошибка", MessageBoxButtons::OK);
					 return;
				 }
			 }

			 //Ищем первый свободный сектор
			 int first_sector;
			 for (int i = 0; i < FAT_table->Rows->Count; i++)
			 {
				 if (Convert::ToInt32(FAT_table->Rows[i]->Cells[1]->Value) == -2)
				 {
					 first_sector = i;
					 break;
				 }
			 }
			 
			 if ((directory == &root) && ((*directory).files.size() + 1 > ROOT_SEC))
			 {
				 MessageBox::Show("В корневом каталоге не может быть больше " + Convert::ToString(ROOT_SEC) + " файлов", "Ошибка", MessageBoxButtons::OK);
				 return;
			 }

			 //Добавляем файл в директорию, если выбран тип файла
			 file new_file;
			 if (choose_catalog->Checked || choose_file->Checked)
			 {
				 int how_sectors_need = 0;
				 if (choose_catalog->Checked)
					 how_sectors_need++;
				 else
				 {
					 how_sectors_need = Convert::ToInt32(enter_size->Value) / SEC_SIZE;
					 if (Convert::ToInt32(enter_size->Value) % SEC_SIZE != 0)
						 how_sectors_need++;
				 }

				 if (fill_sectors + how_sectors_need > 100)
				 {
					 MessageBox::Show("Не хватает памяти для этого файла. Не хватает " + 
						 Convert::ToString(fill_sectors + how_sectors_need - 100) + " секторов", "Ошибка", MessageBoxButtons::OK);
					 return;
				 }

				 //Проверка возможности расширить каталог, если он переполнен(в одном секторе каталог может хранить данные о 4 файлах)
				 if (directory != &root)
				 {
					 int a = (*directory).files.size() + 1;
					 int b = (*directory).count_sectors * (SEC_SIZE / FILE_INFO);
					 if ((a - b) > 0)
					 {
						 if (fill_sectors + how_sectors_need + 1 > 100)
						 {
							 MessageBox::Show("Чтобы добавить файл в этот каталог, нужно выделить дополнительное место для каталога,"
								 + " но для этого не хватает свободного сектора."
								 + " Попробуйте добавить этот файл в другой каталог.", "Ошибка", MessageBoxButtons::OK);
							 return;
						 }
						 else
						 {
							 int prev = (*directory).first_sector;
							 int j = 0;
							 while (prev != -1)
							 {
								 j = prev;
								prev = Convert::ToInt32(FAT_table->Rows[prev]->Cells[1]->Value);
							 }

							 int k;
							 for ( k; k < FAT_table->RowCount; k++)
							 {
								 if (Convert::ToInt32(FAT_table->Rows[k]->Cells[1]->Value) == -2)
									 break;
							 }

							 FAT_table->Rows[j]->Cells[1]->Value = k;
							 FAT_table->Rows[k]->Cells[1]->Value = -1;
							 (*directory).count_sectors++;

							 for (k; k < FAT_table->RowCount; k++)
							 {
								 if (Convert::ToInt32(FAT_table->Rows[k]->Cells[1]->Value) == -2)
									 break;
							 }
							 first_sector = k;
						 }
					 }
				 }


				 new_file = add_file(file_name, choose_catalog->Checked, Convert::ToInt32(enter_size->Value), how_sectors_need, first_sector, directory);
				 fill_sectors += how_sectors_need;
			 }
			 else
			 {
				 MessageBox::Show("Тип файла не выбран", "Ошибка", MessageBoxButtons::OK);
				 return;
			 }

			 //Добавляем информацию о файле в таблицу директории
			 permition = 0;
			 String^ s = gcnew String(new_file.name.c_str());

			 Records_table->Rows->Add();

			 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[0]->Value = s;
			 if (new_file.type)
				 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[1]->Value = "catalog";
			 else
				 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[1]->Value = "file";

			 Records_table->Rows[Records_table->RowCount - 1]->Cells[2]->Value = new_file.size;
			 Records_table->Rows[Records_table->RowCount - 1]->Cells[3]->Value = new_file.first_sector;
			 s = gcnew String(new_file.time_create.c_str());
			 Records_table->Rows[Records_table->RowCount - 1]->Cells[4]->Value = s;
			 s = gcnew String(new_file.time_change.c_str());
			 Records_table->Rows[Records_table->RowCount - 1]->Cells[5]->Value = s;

			 Records_table->Rows[Records_table->RowCount - 1]->ReadOnly = true;
			 Records_table->ClearSelection();

			 permition = 1;

			 //Заполняем FAT таблицу в соответсвии с информацией о файле
			 if (new_file.count_sectors != 0)
			 {
				 if (new_file.count_sectors == 1)
					 FAT_table->Rows[new_file.first_sector]->Cells[1]->Value = -1;
				 else
				 {
					 int prev_sector = new_file.first_sector;
					 int j = 0;
					 FAT_table->Rows[prev_sector]->Cells[1]->Value = -1;
					 for (int i = 0; i < new_file.count_sectors - 1; i++)
					 {
						 for (; j < FAT_table->RowCount; j++)
						 {
							 if (Convert::ToInt32(FAT_table->Rows[j]->Cells[1]->Value) == -2)
								 break;
						 }

						 FAT_table->Rows[prev_sector]->Cells[1]->Value = j;
						 FAT_table->Rows[j]->Cells[1]->Value = -1;
						 prev_sector = j;

					 }
				 }
			 }
}

private: System::Void Records_table_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			//При нажатии на файл в табьлице директории, выбеляются сектора, котоыре занимает файл в FAT таблице
			 if (permition)
			 {
				 permition = 0;
				 open_button->Enabled = true;
				 FAT_table->ClearSelection();

				 if (Convert::ToString(Records_table->CurrentRow->Cells[0]->Value) != "...")
				 {
					 if (Convert::ToInt32(Records_table->CurrentRow->Cells[3]->Value) != -1)
					 {
						 int pos = Convert::ToInt32(Records_table->CurrentRow->Cells[3]->Value);
						 FAT_table->Rows[pos]->Selected = true;
						 while (Convert::ToInt32(FAT_table->Rows[pos]->Cells[1]->Value) != -1)
						 {
							 pos = Convert::ToInt32(FAT_table->Rows[pos]->Cells[1]->Value);
							 FAT_table->Rows[pos]->Selected = true;
						 }
					 }
				 }

				 permition = 1;
			 }
}

private: System::Void open_button_Click(System::Object^  sender, System::EventArgs^  e) {
			//Открываем файл, каталог, возвращаемся в предыдущую директорию

			 if (Convert::ToString(Records_table->CurrentRow->Cells[1]->Value) == "file")
			 {
#pragma region open_file
				 //При открытии файла, его содержимое выводится на экран
				 string file_name;
				 MarshalString(Convert::ToString(Records_table->CurrentRow->Cells[0]->Value), file_name);

				 file_text->ReadOnly = false;
				 permition = 0;
				 for (int i = 0; i < (*directory).files.size(); i++)
				 {
					 if (file_name == (*directory).files[i].name)
					 {
						 String^ s = gcnew String((*directory).files[i].text.c_str());
						 file_text->Text = s;
					 }
				 }
				 permition = 1;
#pragma endregion
			 }
			 else
			 {
				 FAT_table->ClearSelection();
				 if (Convert::ToString(Records_table->CurrentRow->Cells[1]->Value) == "catalog" && Convert::ToString(Records_table->CurrentRow->Cells[0]->Value) != "...")
				 {
#pragma region open_catalog
					 //При открытии каталога, таблица директории перезаписывается  учётом информации о каталоге, в который мы перешли
					 
					 back_path.push_back(directory);
					 //Дописываем в путь имя директории
					 file_path->Text += Records_table->CurrentRow->Cells[0]->Value + "\\";
					 string catalog_name;
					 MarshalString(Convert::ToString(Records_table->CurrentRow->Cells[0]->Value), catalog_name);
					 //непоследственно переходим в директорию
					 for (int i = 0; i < (*directory).files.size(); i++)
					 {
						 if (catalog_name == (*directory).files[i].name)
						 {
							 directory = &(*directory).files[i];
							 break;
						 }
					 }
					 Records_table->Rows->Clear();

					 //Добавляем в таблицу директории возможность вернутсья в предыдущую, создав специальную строку в таблице для этого
					 //(Такая реализация встречается в различных файловых менеджерах)
					 Records_table->Rows->Add();
					 Records_table->Rows[0]->Cells[0]->Value = "...";
					 Records_table->Rows[0]->Cells[1]->Value = "catalog";
					 Records_table->Rows[0]->ReadOnly = true;

					 //В таблицу директорию записываются все файлы, хранящиеся в директории, в которую мы перешли
					 for (int i = 0; i < (*directory).files.size(); i++)
					 {
						 String^ s = gcnew String((*directory).files[i].name.c_str());

						 Records_table->Rows->Add();

						 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[0]->Value = s;
						 if ((*directory).files[i].type)
							 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[1]->Value = "catalog";
						 else
							 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[1]->Value = "file";

						 Records_table->Rows[Records_table->RowCount - 1]->Cells[2]->Value = (*directory).files[i].size;
						 Records_table->Rows[Records_table->RowCount - 1]->Cells[3]->Value = (*directory).files[i].first_sector;
						 s = gcnew String((*directory).files[i].time_create.c_str());
						 Records_table->Rows[Records_table->RowCount - 1]->Cells[4]->Value = s;
						 s = gcnew String((*directory).files[i].time_change.c_str());
						 Records_table->Rows[Records_table->RowCount - 1]->Cells[5]->Value = s;

						 Records_table->Rows[Records_table->RowCount - 1]->ReadOnly = true;
					 }

					 Records_table->ClearSelection();
					 FAT_table->ClearSelection();
					 open_button->Enabled = false;
					 create_button->Enabled = true;
#pragma endregion
				 }
				 else
				 {
#pragma region back
					 //если мы возвращаемся в предыдущую директорию, то таблица переписывается в соответствии с информацией о предыдущей дирекутории
					 Records_table->Rows->Clear();
					 String^ s;
					 file_path->Text = "";

					 //Изменяем путь
					 for (int i = 0; i < back_path.size(); i++)
					 {
						 s = gcnew String((*back_path[i]).name.c_str());
						 file_path->Text += s + "\\";
					 }

					 //Непосредственно возвращаемся в директорию
					 directory = back_path[back_path.size() - 1];
					 back_path.erase(back_path.end() - 1);

					 //Если это не корневая директория, то снова добавляем возможность вернуться в предыдущую директорию
					 if (back_path.size() != 0)
					 {
						 Records_table->Rows->Add();
						 Records_table->Rows[0]->Cells[0]->Value = "BACK____";
						 Records_table->Rows[0]->Cells[1]->Value = "...";
						 Records_table->Rows[0]->ReadOnly = true;
					 }

					 //Заполняем таблицу директории файлами из директории, в которую мы вернулись
					 for (int i = 0; i < (*directory).files.size(); i++)
					 {
						 s = gcnew String((*directory).files[i].name.c_str());

						 Records_table->Rows->Add();

						 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[0]->Value = s;
						 if ((*directory).files[i].type)
							 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[1]->Value = "catalog";
						 else
							 Records_table->Rows[Records_table->Rows->Count - 1]->Cells[1]->Value = "file";

						 Records_table->Rows[Records_table->RowCount - 1]->Cells[2]->Value = (*directory).files[i].size;
						 Records_table->Rows[Records_table->RowCount - 1]->Cells[3]->Value = (*directory).files[i].first_sector;
						 s = gcnew String((*directory).files[i].time_create.c_str());
						 Records_table->Rows[Records_table->RowCount - 1]->Cells[4]->Value = s;
						 s = gcnew String((*directory).files[i].time_change.c_str());
						 Records_table->Rows[Records_table->RowCount - 1]->Cells[5]->Value = s;

						 Records_table->Rows[Records_table->RowCount - 1]->ReadOnly = true;
					 }

					 Records_table->ClearSelection();
					 FAT_table->ClearSelection();
					 open_button->Enabled = false;
					 create_button->Enabled = true;
#pragma endregion
				 }
			 }
}

private: System::Void Records_table_SelectionChanged(System::Object^  sender, System::EventArgs^  e) {
			//При выборе другого файла в таблице директории, содержимое предыдущего файла(если он был открыт), очищается, возможность изменить его пропадает	 
			 file_text->ReadOnly = true;
			 file_text->Text = "";
			 change_file_text_button->Enabled = false;
}

private: System::Void file_text_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (permition)
			 change_file_text_button->Enabled = true;
}

private: System::Void change_file_text_button_Click(System::Object^  sender, System::EventArgs^  e) {
				 change_file_text_button->Enabled = false;

				 string file_name;
				 MarshalString(Convert::ToString(Records_table->CurrentRow->Cells[0]->Value), file_name);

				 for (int i = 0; i < (*directory).files.size(); i++)
				 {
					 if (file_name == (*directory).files[i].name)
					 {
						 String^ s = gcnew String((*directory).files[i].text.c_str());
						 if (s != file_text->Text)
						 {
#pragma region Если изменение было
							 
							 //считаем, на сколкьо изменилось коилчество секторов
							 int count_sectors_changed = file_text->TextLength / SEC_SIZE;
							 if (file_text->TextLength % SEC_SIZE != 0)
								 count_sectors_changed++;

							 int sectors_differense = count_sectors_changed - (*directory).files[i].count_sectors;
							 //Проверка нехватки памяти
							 if (fill_sectors + sectors_differense > 100)
							 {
								 MessageBox::Show("Не хватает памяти для этого изменения. Доступно " 
									 + Convert::ToString((*directory).files[i].count_sectors * SEC_SIZE - (*directory).files[i].size) + 
									 " байт памяти", "Ошибка", MessageBoxButtons::OK);
								 permition = 0;
								 file_text->Text = s;
								 permition = 1;
								 return;
							 }
							 //Изменяем характеристики файла при изменении его содержтмого(время изменения, размер, количество кластеров)
							 string text;
							 MarshalString(Convert::ToString(file_text->Text), text);
							 (*directory).files[i].text = text;
							 (*directory).files[i].size = Convert::ToInt32(file_text->TextLength);
							 Records_table->CurrentRow->Cells[2]->Value = file_text->TextLength;
							 time_t t = time(NULL);
							 string time = ctime(&t);
							 (*directory).files[i].time_change = time.substr(11, 8);
							 s = gcnew String(time.substr(11, 8).c_str());
							 Records_table->CurrentRow->Cells[5]->Value = s;

							 vector<int> klaster;

							 int prev_sector = (*directory).files[i].first_sector;
							 permition = 0;
							 //Находим кластер секторов, занимаемый файлом
							 for (int j = 0; j < (*directory).files[i].count_sectors; j++)
							 {
								 klaster.push_back(prev_sector);
								 FAT_table->Rows[prev_sector]->Selected = true;
								 prev_sector = Convert::ToInt32(FAT_table->Rows[prev_sector]->Cells[1]->Value);
							 }

							 (*directory).files[i].count_sectors = count_sectors_changed;
							 fill_sectors += sectors_differense;

							 //Если секторов стало меньше, освобождаем ненужные
							 //Если стало больше, добавляем свободные сектора
							 if (sectors_differense < 0)
							 {
								 sectors_differense = abs(sectors_differense);
								 if ((*directory).files[i].size == 0)
								 {
									 FAT_table->ClearSelection();
									 for (int j = 0; j < klaster.size(); j++)
										 FAT_table->Rows[klaster[j]]->Cells[1]->Value = -2;
									 Records_table->CurrentRow->Cells[3]->Value = -1;
									 (*directory).files[i].first_sector = -1;
								 }
								 else
								 {
									 for (int j = 0; j < sectors_differense; j++)
									 {
										 FAT_table->Rows[klaster[klaster.size() - (1 + j)]]->Cells[1]->Value = -2;
										 FAT_table->Rows[klaster[klaster.size() - (1 + j)]]->Selected = false;
										 FAT_table->Rows[klaster[klaster.size() - (2 + j)]]->Cells[1]->Value = -1;
									 }
								 }

							 }
							 else
							 {
								 if (sectors_differense > 0)
								 {
									 if (prev_sector == -1)
									 {
										 prev_sector = 0;
										 for (; prev_sector < FAT_table->RowCount; prev_sector++)
											 if (Convert::ToInt32(FAT_table->Rows[prev_sector]->Cells[1]->Value) == -2)
												 break;

										 //(*directory).files[i].first_sector = prev_sector;
										 int pos = (*directory).files[i].first_sector;
										 while (Convert::ToInt32(FAT_table->Rows[pos]->Cells[1]->Value) != -1)
										 {
											 pos = Convert::ToInt32(FAT_table->Rows[Convert::ToInt32(FAT_table->Rows[pos]->Cells[1]->Value)]->Cells[0]->Value);
										 }

										 FAT_table->Rows[pos]->Cells[1]->Value = prev_sector;
										 FAT_table->Rows[prev_sector]->Cells[1]->Value = -1;
										 FAT_table->Rows[prev_sector]->Selected = true;

										 int j = 0;
										 while (sectors_differense - 1)
										 {
											 for (; j < FAT_table->RowCount; j++)
											 if (Convert::ToInt32(FAT_table->Rows[j]->Cells[1]->Value) == -2)
												 break;

											 FAT_table->Rows[prev_sector]->Cells[1]->Value = j;
											 FAT_table->Rows[j]->Cells[1]->Value = -1;
											 FAT_table->Rows[j]->Selected = true;;
											 prev_sector = j;
											 sectors_differense--;
										 }
									 }
									 else
									 {
										 int prev_sector = klaster[klaster.size() - 1];
										 int j = 0;

										 while (sectors_differense)
										 {
											 for (; j < FAT_table->RowCount; j++)
											 {
												 if (Convert::ToInt32(FAT_table->Rows[j]->Cells[1]->Value) == -2)
													 break;
											 }

											 FAT_table->Rows[j]->Cells[1]->Value = -1;
											 FAT_table->Rows[j]->Selected = true;
											 FAT_table->Rows[prev_sector]->Cells[1]->Value = j;
											 prev_sector = j;

											 sectors_differense--;
										 }
									 }
								 }
							 }
#pragma endregion
						 }
						 permition = 1;
						 break;
					 }


				 }
}
};
}