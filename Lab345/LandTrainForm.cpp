#include "LandTrainForm.h"

using namespace Autopark;

string LandTrainForm::getNormalString(String^ str) {
	return msclr::interop::marshal_as<string>(str);
}

String^ LandTrainForm::getLocalString(string str) {
	return msclr::interop::marshal_as<String^>(str);
}

TRAILER_ARRANGEMENT getArrangementType(int ind) {
	switch (ind) {
	case 0:
		return TRAILER_ARRANGEMENT::A_DOUBLE;
		break;
	case 1:
		return TRAILER_ARRANGEMENT::B_DOUBLE;
		break;
	case 2:
		return TRAILER_ARRANGEMENT::B_TRIPLE;
		break;
	case 3:
		return TRAILER_ARRANGEMENT::AB_TRIPLE;
		break;
	case 4:
		return TRAILER_ARRANGEMENT::A_TRIPLE;
		break;
	case 5:
		return TRAILER_ARRANGEMENT::BAB_QUAD;
		break;
	case 6:
		return TRAILER_ARRANGEMENT::C_TRAIN;
		break;
	case 7:
		return TRAILER_ARRANGEMENT::DOG_TRAILER;
		break;
	}
	return TRAILER_ARRANGEMENT::A_DOUBLE;
}

System::Void LandTrainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	size_t cargoLoad = stoi(getNormalString(textBox7->Text));
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

	int selectedConnection = comboBox1->SelectedIndex;

	if (FILL_FORM == 4) {
		LandTrain* pointer = (LandTrain*)examined;

		pointer->getVehicleEngine()->setEngineModel(engineModel);
		pointer->getVehicleEngine()->setHorsePower(hp);
		pointer->setVehicleName(name);
		pointer->setVehicleOwner(owner);
		pointer->setWheels(Wheel{ tire }, 4);
		pointer->setWindow(Window{ glass });
		pointer->setDoor(Door{ lock });
		pointer->setCargoLoad(cargoLoad);
		pointer->setArrangementType(getArrangementType(selectedConnection));
	}
	else {
		vlist.add(make_unique<LandTrain>(getArrangementType(selectedConnection), cargoLoad, name, hp, name, owner, wheels, wnd, door));
	}

	this->Close();
}

System::Void LandTrainForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

