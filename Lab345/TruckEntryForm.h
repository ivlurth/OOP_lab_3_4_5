#pragma once

#include <msclr\marshal_cppstd.h>
#include "Truck.h"
#include "Globals.h"


namespace Autopark {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TruckEntryForm
	/// </summary>
	public ref class TruckEntryForm : public System::Windows::Forms::Form
	{
	public:
		TruckEntryForm(void)
		{
			InitializeComponent();
			
			if (FILL_FORM == 3) {
				textBox1->Text = getLocalString(engineName);
				textBox8->Text = getLocalString(horsepower);
				textBox2->Text = getLocalString(vehicleName);
				textBox3->Text = getLocalString(owner);
				textBox4->Text = getLocalString(tyre);
				textBox5->Text = getLocalString(glass);
				textBox6->Text = getLocalString(lock2);
				textBox7->Text = getLocalString(weight);
				checkBox1->Checked = hasForkLift;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TruckEntryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox8;
	protected:
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(170, 37);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(180, 22);
			this->textBox8->TabIndex = 39;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 37);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 17);
			this->label9->TabIndex = 38;
			this->label9->Text = L"Л.С.";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(191, 321);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 37;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TruckEntryForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(84, 321);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 36;
			this->button1->Text = L"ОК";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TruckEntryForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(251, 285);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(59, 21);
			this->checkBox1->TabIndex = 35;
			this->checkBox1->Text = L"есть";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(170, 224);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(180, 22);
			this->textBox7->TabIndex = 34;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(170, 190);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(180, 22);
			this->textBox6->TabIndex = 33;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(170, 161);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(180, 22);
			this->textBox5->TabIndex = 32;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(170, 128);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(180, 22);
			this->textBox4->TabIndex = 31;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(170, 99);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(180, 22);
			this->textBox3->TabIndex = 30;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(170, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(180, 22);
			this->textBox2->TabIndex = 29;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(170, 9);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(180, 22);
			this->textBox1->TabIndex = 28;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(11, 285);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(191, 17);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Вилочный грузоподъёмник:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 224);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(92, 17);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Масса груза:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 190);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 17);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Тип дверей:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 161);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 17);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Тип окон:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 17);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Тип колёс:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 17);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Владелец:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 17);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Имя транспорта:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 17);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Модель двигателя: ";
			// 
			// TruckEntryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(367, 357);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"TruckEntryForm";
			this->Text = L"TruckEntryForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		string getNormalString(String^ str);
		String^ getLocalString(string str);

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
