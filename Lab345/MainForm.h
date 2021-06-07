#pragma once

#include "Vehicle.h"
#include "VehicleList.h"
#include "Crossover.h"
#include "Limousine.h"
#include "Pickup.h"
#include "Truck.h"
#include "LandTrain.h"
#include "NewEntryForm.h"
#include <msclr\marshal_cppstd.h>
#include <memory>
#include "Globals.h"

using namespace std;
VehicleList vlist;
int FILL_FORM = -1;


string engineName;
string horsepower;
string vehicleName;
string owner;
string tyre;
string glass;
string lock2;
string passengerCapacity;
bool hasAllDrive;
string length;
string weight;
bool hasForkLift;
int connection;
Vehicle* examined = nullptr;

enum class TransportType {
	CROSSOVER,
	LIMOUSINE,
	PICKUP,
	TRUCK,
	LAND_TRAIN,
	TYPE_ERROR
};

namespace Autopark {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();


			vector<Wheel> wheels(4, Wheel{ "Winter tyre" });
			vlist.add(make_unique<Crossover>(true, 4, "THX-1138", 1500, "Lada-Kalina", "Влад Костян", wheels, Window{ "Tanned" }, Door{ "Automatic" }));
			vlist.add(make_unique<Limousine>(1280, 345, "FF-6u7", 2700, "Maybah", "A. Navalny", wheels, Window{ "Ocean Blue" }, Door{ "Electric" }));
			vlist.add(make_unique<Pickup>(8000, 1, "DTY-099", 3330, "Mercedes Benze", "Putin V. V.", wheels, Window{ "Gloomy Dark" }, Door{ "Mechanic" }));
			vlist.add(make_unique<Truck>(false, 5000, "QQR-30", 4300, "Volwswagen", "Plotnikov V. V.", wheels, Window{ "Metallic Grey" }, Door{ "Stylish" }));
			vlist.add(make_unique<LandTrain>(TRAILER_ARRANGEMENT::B_TRIPLE, 10000, "ZXCV", 47790, "Mitsubishi", "Akira Yaaoka", wheels, Window{ "Sunlight" }, Door{ "Solemn" }));


			for (auto& it : vlist) {
				addItemToTheList(it.get());
			}

		}


		string getNormalString(String^ str);
		String^ getLocalString(string str);
		string getVehicleTypeName(TransportType tt);
		void addItemToTheList(Vehicle* ptr);
		TransportType getType(Vehicle* ptr);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			vlist.clear();
		}

		System::Windows::Forms::ListViewItem^ listViewItem;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;


	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripComboBox^ toolStripComboBox1;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->FullRowSelect = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 27);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(546, 262);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listView1_SelectedIndexChanged);
			this->listView1->DoubleClick += gcnew System::EventHandler(this, &MainForm::listView1_DoubleClick);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Тип транспорта";
			this->columnHeader1->Width = 182;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Название";
			this->columnHeader2->Width = 102;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Владелец";
			this->columnHeader3->Width = 86;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(204, 306);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Новый транспорт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(204, 335);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(151, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Удалить транспорт";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripButton1,
					this->toolStripButton2, this->toolStripLabel1, this->toolStripComboBox1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(570, 28);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(95, 25);
			this->toolStripButton1->Text = L"Открыть .txt";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(111, 25);
			this->toolStripButton2->Text = L"Сохранить .txt";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton2_Click);
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(105, 25);
			this->toolStripLabel1->Text = L"Шифрование:";
			this->toolStripLabel1->Click += gcnew System::EventHandler(this, &MainForm::toolStripLabel1_Click);
			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->toolStripComboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"-Нет-", L"AES", L"RC6", L"Aria" });
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->SelectedIndex = 0;
			this->toolStripComboBox1->Size = System::Drawing::Size(121, 28);
			this->toolStripComboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::toolStripComboBox1_SelectedIndexChanged);
			this->toolStripComboBox1->Click += gcnew System::EventHandler(this, &MainForm::toolStripComboBox1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 369);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Name = L"MainForm";
			this->Text = L"Автопарк";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void listView1_DoubleClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void toolStripComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripLabel1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
