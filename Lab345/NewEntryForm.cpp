#include "NewEntryForm.h"

using namespace Autopark;

System::Void NewEntryForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int SelectedIndex = comboBox1->SelectedIndex;

		switch (SelectedIndex) {
		case 0: {
			CrossoverEntryForm^ form = gcnew CrossoverEntryForm;
			this->Hide();
			form->ShowDialog();
			this->Show();
			break;
		}
		case 1: {
			LimousineEntryForm^ form = gcnew LimousineEntryForm;
			this->Hide();
			form->ShowDialog();
			this->Show();
			break;
		}
		case 2: {
			PickupEntryForm^ form = gcnew PickupEntryForm;
			this->Hide();
			form->ShowDialog();
			this->Show();
			break;
		}
		case 3: {
			TruckEntryForm^ form = gcnew TruckEntryForm;
			this->Hide();
			form->ShowDialog();
			this->Show();
			break;
		}
		case 4: {
			LandTrainForm^ form = gcnew LandTrainForm;
			this->Hide();
			form->ShowDialog();
			this->Show();
			break;
		}
		}
	}

System::Void NewEntryForm::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}

System::Void NewEntryForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
