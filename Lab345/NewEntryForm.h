#pragma once

#include "CrossoverEntryForm.h"
#include "LimousineEntryForm.h"
#include "PickupEntryForm.h"
#include "TruckEntryForm.h"
#include "LandTrainForm.h"

namespace Autopark {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NewEntryForm
	/// </summary>
	public ref class NewEntryForm : public System::Windows::Forms::Form
	{
	public:
		NewEntryForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewEntryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 42);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ОК";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewEntryForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(134, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(123, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NewEntryForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Crossover", L"Limousine", L"Pickup", L"Truck",
					L"Land-train"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(245, 24);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &NewEntryForm::comboBox1_SelectedIndexChanged);
			// 
			// NewEntryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(269, 82);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"NewEntryForm";
			this->Text = L"NewEntryForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
