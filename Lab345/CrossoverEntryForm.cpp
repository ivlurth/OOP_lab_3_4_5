#include "CrossoverEntryForm.h"

using namespace Autopark;

string CrossoverEntryForm::getNormalString(String^ str) {
	return msclr::interop::marshal_as<string>(str);
}

String^ CrossoverEntryForm::getLocalString(string str) {
	return msclr::interop::marshal_as<String^>(str);
}


System::Void CrossoverEntryForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}

System::Void CrossoverEntryForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	bool fullTimeAllDrive = checkBox1->Checked;
	size_t capacity = stoi(getNormalString(textBox7->Text));
	string engineModel = getNormalString(textBox1->Text);
	size_t hp = stoi(getNormalString(textBox8->Text));
	string name = getNormalString(textBox2->Text);
	string owner = getNormalString(textBox3->Text);
	string tire = getNormalString(textBox4->Text);
	vector<Wheel> wheels(4, Wheel{ tire });
	string glass = getNormalString(textBox5->Text);
	Window wnd{ glass };
	string lock = getNormalString(textBox6->Text);
	Door door{ lock };

	if (FILL_FORM == 0) {
		Crossover* pointer = (Crossover*)examined;

		pointer->getVehicleEngine()->setEngineModel(engineModel);
		pointer->getVehicleEngine()->setHorsePower(hp);
		pointer->setVehicleName(name);
		pointer->setVehicleOwner(owner);
		pointer->setWheels(Wheel{tire}, 4);
		pointer->setWindow(Window{glass});
		pointer->setDoor(Door{lock});
		pointer->setPassengerCount(capacity);
		pointer->setFullTimeAllDrive(fullTimeAllDrive);
	}
	else {

		vlist.add(make_unique<Crossover>(fullTimeAllDrive, capacity, name, hp, name, owner, wheels, wnd, door));
	}

	this->Close();
}

System::Void CrossoverEntryForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
