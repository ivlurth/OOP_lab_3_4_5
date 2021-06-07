#include "MainForm.h"
#include "Windows.h"
#include <fstream>

using namespace Autopark;
using namespace std;


int ENCRYPT_STATE = 0;


string MainForm::getNormalString(String^ str) {
	return msclr::interop::marshal_as<string>(str);
}

String^ MainForm::getLocalString(string str) {
	return msclr::interop::marshal_as<String^>(str);
}

string MainForm::getVehicleTypeName(TransportType tt) {
	switch (tt) {
	case TransportType::CROSSOVER:
		return "Crossover";
		break;
	case TransportType::LIMOUSINE:
		return "Limousine";
		break;
	case TransportType::PICKUP:
		return "Pickup";
		break;
	case TransportType::TRUCK:
		return "Truck";
		break;
	case TransportType::LAND_TRAIN:
		return "Land train";
		break;
	}
	return "WRONG";
}

void MainForm::addItemToTheList(Vehicle* ptr) {
	listViewItem = gcnew Windows::Forms::ListViewItem(getLocalString(getVehicleTypeName(getType(ptr))));
	listViewItem->SubItems->Add(getLocalString(ptr->getVehicleName()));
	listViewItem->SubItems->Add(getLocalString(ptr->getVehicleOwner()));
	this->listView1->Items->Add(this->listViewItem);
}

TransportType MainForm::getType(Vehicle* ptr) {
	if (dynamic_cast<Crossover*>(ptr))
		return TransportType::CROSSOVER;
	else if (dynamic_cast<Limousine*>(ptr))
		return TransportType::LIMOUSINE;
	else if (dynamic_cast<Pickup*>(ptr))
		return TransportType::PICKUP;
	else if (dynamic_cast<Truck*>(ptr))
		return TransportType::TRUCK;
	else if (dynamic_cast<LandTrain*>(ptr))
		return TransportType::LAND_TRAIN;
	else return TransportType::TYPE_ERROR;
}

void refreshList(System::Windows::Forms::ListView^ list, MainForm^ mForm) {
	list->Items->Clear();
	for (auto& it : vlist) {
		mForm->addItemToTheList(it.get());
	}
}

void fillCommonData(Automobile* vh) {
	engineName = vh->getVehicleEngine()->getEngineModel();
	horsepower = to_string(vh->getVehicleEngine()->getHorsePower());
	vehicleName = vh->getVehicleName();
	owner = vh->getVehicleOwner();
	tyre = vh->getWheels().at(0).getTyre();
	glass = vh->getWindow().getGlass();
	lock2 = vh->getDoor().getLock();
}

void fillCrossOverData(Crossover* vh) {
	fillCommonData((Automobile*)vh);
	passengerCapacity = to_string(vh->getPassengerCount());
	hasAllDrive = vh->isFullTimeAllDrive();
}

byte _rand() {
	static int mycount = 0;
	static bool check = false;
	if (mycount == 32) mycount = 0;
	static byte __ar[32];
	if (!check) {
		for (int i = 0; i < 32; i++) {
			__ar[i] = rand() % 10;
		}
		check = true;
	}
	mycount++;
	return __ar[mycount - 1];
}

void fillCrossOverData(Limousine* vh) {
	fillCommonData((Automobile*)vh);
	passengerCapacity = to_string(vh->getPassengerCount());
	length = to_string(vh->getLength());
}

void fillCrossOverData(Pickup *vh) {
	fillCommonData((Automobile*)vh);
	passengerCapacity = to_string(vh->getPassengerCount());
	weight = to_string(vh->getCargoLoad());
}

void fillCrossOverData(Truck* vh) {
	fillCommonData((Automobile*)vh);
	weight = to_string(vh->getCargoLoad());
	hasForkLift = vh->hasForkLift();
}

int getIndexFromType(TRAILER_ARRANGEMENT ta) {
	switch (ta) {
	case TRAILER_ARRANGEMENT::A_DOUBLE:
		return 0;
	case TRAILER_ARRANGEMENT::B_DOUBLE:
		return 1;
	case TRAILER_ARRANGEMENT::B_TRIPLE:
		return 2;
	case TRAILER_ARRANGEMENT::AB_TRIPLE:
		return 3;
	case TRAILER_ARRANGEMENT::A_TRIPLE:
		return 4;
	case TRAILER_ARRANGEMENT::BAB_QUAD:
		return 5;
	case TRAILER_ARRANGEMENT::C_TRAIN:
		return 6;
	case TRAILER_ARRANGEMENT::DOG_TRAILER:
		return 7;
	}
	return 0;
}

void fillCrossOverData(LandTrain* vh) {
	fillCommonData((Automobile*)vh);
	weight = to_string(vh->getCargoLoad());
	connection = getIndexFromType(vh->getArrangementType());
}

System::Void MainForm::listView1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
			size_t selectedIndex = listView1->SelectedIndices[0];
			Vehicle* pointer = vlist.getPointerAt(selectedIndex);
			TransportType tt = getType(pointer);

			examined = pointer;

			switch (tt) {
			case TransportType::CROSSOVER: {
				FILL_FORM = 0;
				fillCrossOverData((Crossover*)pointer);
				CrossoverEntryForm^ form = gcnew CrossoverEntryForm;
				this->Hide();
				form->ShowDialog();
				this->Show();
				break;
			}
			case TransportType::LIMOUSINE: {
				FILL_FORM = 1;
				fillCrossOverData((Limousine*)pointer);
				LimousineEntryForm^ form = gcnew LimousineEntryForm;
				this->Hide();
				form->ShowDialog();
				this->Show();
				break;
			}
			case TransportType::PICKUP: {
				FILL_FORM = 2;
				fillCrossOverData((Pickup*)pointer);
				PickupEntryForm^ form = gcnew PickupEntryForm;
				this->Hide();
				form->ShowDialog();
				this->Show();
				break;
			}
			case TransportType::TRUCK: {
				FILL_FORM = 3;
				fillCrossOverData((Truck*)pointer);
				TruckEntryForm^ form = gcnew TruckEntryForm;
				this->Hide();
				form->ShowDialog();
				this->Show();
				break;
			}
			case TransportType::LAND_TRAIN: {
				FILL_FORM = 4;
				fillCrossOverData((LandTrain*)pointer);
				LandTrainForm^ form = gcnew LandTrainForm;
				this->Hide();
				form->ShowDialog();
				this->Show();
				break;
			}
			}

			FILL_FORM = -1;
			refreshList(listView1, this);
		}

System::Void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
			NewEntryForm^ form = gcnew NewEntryForm;
			this->Hide();
			size_t oldSize = vlist.size();
			form->ShowDialog();
			this->Show();


			if (oldSize < vlist.size()) {
				size_t N = 0;
				for (auto it = vlist.begin(); it != vlist.end(); it++, N++) {
					if (N <= oldSize - 1 && oldSize != 0) continue;
					addItemToTheList(it->get());
				}
			}
		}

System::Void MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listView1->SelectedIndices->Count > 0) {
		size_t ind = listView1->SelectedIndices[0];
		listView1->Items->RemoveAt(ind);
		vlist.remove(ind);
	}
}




System::Void MainForm::listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
System::Void MainForm::toolStripLabel1_Click(System::Object^ sender, System::EventArgs^ e) {}
System::Void MainForm::toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e) {}



[System::STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm);

    return 0;
}


#include <cryptlib.h>
#include <secblock.h>
#include <chacha.h>
#include <osrng.h>
#include <files.h>
#include <hex.h>
#include <modes.h>
#include <rc6.h>
#include <aria.h>

using namespace CryptoPP;
using CryptoPP::AutoSeededRandomPool;
using CryptoPP::StringSink;
using CryptoPP::StreamTransformation;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::AES;
using CryptoPP::CBC_Mode;




//ŒŒœ  À¿——€
/////////////////////////////////=========================================================================================

class FileInputOutput {
public:
	void write_to_file(const string& path, VehicleList& vlist) {
		ofstream out(path);
		out << vlist.size() << endl;
		out << ENCRYPT_STATE << endl;
		generate_block_values();
		write_encryption_additional_info(out);
		for (auto& it : vlist) {
			out << get_item_info_string_to_write(it->getDescription());
		}
		out.close();
	}

	void read_from_file(ifstream& in, VehicleList& vlist, int N) {
		vlist.clear();
		string type, buf;
		read_block_values(in);

		for (int i = 0; i < N; ++i) {
			getline(in, type);
			type = get_item_info_string_to_read(type);

			getline(in, engineName);
			engineName = get_item_info_string_to_read(engineName);

			getline(in, buf);
			buf = get_item_info_string_to_read(buf);
			int hp = stoi(buf);

			getline(in, vehicleName);
			vehicleName = get_item_info_string_to_read(vehicleName);
			getline(in, owner);
			owner = get_item_info_string_to_read(owner);

			getline(in, buf);
			buf = get_item_info_string_to_read(buf);
			int wheelCount = stoi(buf);


			getline(in, tyre);
			tyre = get_item_info_string_to_read(tyre);
			getline(in, glass);
			glass = get_item_info_string_to_read(glass);
			getline(in, lock2);
			lock2 = get_item_info_string_to_read(lock2);

			vector<Wheel> wheels(wheelCount, Wheel{ tyre });

			if (type == "Crossover") {
				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int passCount = stoi(buf);

				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				hasAllDrive = stoi(buf);
				vlist.add(make_unique<Crossover>(hasAllDrive, passCount, engineName, hp, vehicleName, owner, wheels, Window{ glass }, Door{ lock2 }));
			}
			else if (type == "Limousine") {
				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int passCount = stoi(buf);

				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int lLength = stoi(buf);
				vlist.add(make_unique<Limousine>(lLength, passCount, engineName, hp, vehicleName, owner, wheels, Window{ glass }, Door{ lock2 }));
			}
			else if (type == "Pickup") {
				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int passCount = stoi(buf);

				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int cargoLoad = stoi(buf);
				vlist.add(make_unique<Pickup>(cargoLoad, passCount, engineName, hp, vehicleName, owner, wheels, Window{ glass }, Door{ lock2 }));
			}
			else if (type == "Truck") {
				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int cargoLoad = stoi(buf);

				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				bool hasLift = stoi(buf);
				vlist.add(make_unique<Truck>(hasLift, cargoLoad, engineName, hp, vehicleName, owner, wheels, Window{ glass }, Door{ lock2 }));
			}
			else if (type == "LandTrain") {
				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int cargoLoad = stoi(buf);

				getline(in, buf);
				buf = get_item_info_string_to_read(buf);
				int anotherType = stoi(buf);

				TRAILER_ARRANGEMENT ta;

				switch (anotherType) {
				case 0:
					ta = TRAILER_ARRANGEMENT::A_DOUBLE;
					break;
				case 1:
					ta = TRAILER_ARRANGEMENT::B_DOUBLE;
					break;
				case 2:
					ta = TRAILER_ARRANGEMENT::B_TRIPLE;
					break;
				case 3:
					ta = TRAILER_ARRANGEMENT::AB_TRIPLE;
					break;
				case 4:
					ta = TRAILER_ARRANGEMENT::A_TRIPLE;
					break;
				case 5:
					ta = TRAILER_ARRANGEMENT::BAB_QUAD;
					break;
				case 6:
					ta = TRAILER_ARRANGEMENT::C_TRAIN;
					break;
				case 7:
					ta = TRAILER_ARRANGEMENT::DOG_TRAILER;
					break;
				}

				vlist.add(make_unique<LandTrain>(ta, cargoLoad, engineName, hp, vehicleName, owner, wheels, Window{ glass }, Door{ lock2 }));
			}
		}
		in.close();
	}

protected:
	virtual void generate_block_values() = 0;
	virtual void read_block_values(ifstream& in) = 0;
	virtual void write_encryption_additional_info(ofstream& out) = 0;
	virtual string get_item_info_string_to_write(string description) = 0;
	virtual string get_item_info_string_to_read(string description) = 0;
};


class NoEncryptionIO : public FileInputOutput {
protected:
	virtual void generate_block_values() override { }
	virtual void write_encryption_additional_info(ofstream& out) override { }
	virtual string get_item_info_string_to_write(string description) override {
		return description;
	}
	virtual void read_block_values(ifstream& in) override { }
	virtual string get_item_info_string_to_read(string description) override {
		return description;
	}
};

class EncryptionAlgorithm {
protected:
	static constexpr size_t SIZE = 16;
	AutoSeededRandomPool prng;
	SecByteBlock key{SIZE};
	SecByteBlock iv {SIZE};
public:
	virtual string doEncryption(string msg) = 0;
	virtual string undoEncryption(string cipher) = 0;
	void generateEncryptionInfo() {
		prng.GenerateBlock(key, key.size());
		prng.GenerateBlock(iv, sizeof(iv));
	}

	string getEncryptionInfo() {
		stringstream ss;

		for (size_t i = 0; i < SIZE; ++i) {
			ss << (int)key[i] << endl;
		}
		for (size_t i = 0; i < SIZE; ++i) {
			ss << (int)iv[i] << endl;
		}

		return ss.str();
	}

	void readEncryptionInfo(ifstream& in) {
		string buf;
		for (size_t i = 0; i < SIZE; ++i) {
			getline(in, buf);
			key[i] = stoi(buf);
		}
		for (size_t i = 0; i < SIZE; ++i) {
			getline(in, buf);
			iv[i] = stoi(buf);
		}
	}
};

class AES_Encryption : public EncryptionAlgorithm {
public:
	virtual string doEncryption(string msg) override {
		string encText;

		CryptoPP::CTR_Mode< CryptoPP::AES >::Encryption enc;
		enc.SetKeyWithIV(key, sizeof(key), iv);
		CryptoPP::StreamTransformationFilter encFilter(enc, new CryptoPP::StringSink(encText));

		encFilter.Put(reinterpret_cast<const byte*>(msg.c_str()), msg.size());
		encFilter.MessageEnd();

		return encText;
	}

	virtual string undoEncryption(string cipher) override {
		string decoded;

		CryptoPP::CTR_Mode< CryptoPP::AES >::Decryption dec;
		dec.SetKeyWithIV(key, sizeof(key), iv);
		CryptoPP::StreamTransformationFilter decFilter(dec, new CryptoPP::StringSink(decoded));
		
		decFilter.Put(reinterpret_cast<const byte*>(cipher.c_str()), cipher.size());
		decFilter.MessageEnd();

		return decoded;
	}
};

class RC6_Encryption : public EncryptionAlgorithm {
public:
	virtual string doEncryption(string msg) override {
		string encText;

		CBC_Mode< RC6 >::Encryption e;
		e.SetKeyWithIV(key, key.size(), iv);
		StringSource(msg, true, new StreamTransformationFilter(e, new StringSink(encText)));

		return encText;
	}

	virtual string undoEncryption(string cipher) override {
		string decoded;

		CBC_Mode< RC6 >::Decryption d;
		d.SetKeyWithIV(key, key.size(), iv);
		StringSource s(cipher, true, new StreamTransformationFilter(d, new StringSink(decoded)));

		return decoded;
	}
};

class Aria_Encryption : public EncryptionAlgorithm {
public:
	virtual string doEncryption(string msg) override {
		string encText;

		CBC_Mode< ARIA >::Encryption e;
		e.SetKeyWithIV(key, key.size(), iv);
		StringSource s(msg, true, new StreamTransformationFilter(e, new StringSink(encText)));
	
		return encText;
	}

	virtual string undoEncryption(string cipher) override {
		string decoded;

		CBC_Mode< ARIA >::Decryption d;
		d.SetKeyWithIV(key, key.size(), iv);
		StringSource s(cipher, true, new StreamTransformationFilter(d, new StringSink(decoded)));

		return decoded;
	}
};

class Encryption {
private:
	EncryptionAlgorithm* specific_encryption = nullptr;
public:
	string getEncryptedString(string token) {
		return specific_encryption->doEncryption(token);
	}

	void generateKeyIVblocks() {
		specific_encryption->generateEncryptionInfo();
	}

	string getKeyIVstring() {
		return specific_encryption->getEncryptionInfo();
	}

	void readKeyIVblocks(ifstream& in) {
		specific_encryption->readEncryptionInfo(in);
	}

	void set_encryption_algorithm(EncryptionAlgorithm* pointer) { specific_encryption = pointer; }

	string getDeencryptedString(string cipher) {
		return specific_encryption->undoEncryption(cipher);
	}
};

class EncryptionAdapter : public FileInputOutput {
private:
	Encryption* adaptee = nullptr;
protected:
	virtual string get_item_info_string_to_write(string description) override {
		stringstream ss;
		size_t pos = 0;
		std::string token, cipher, HEX_encoded, delimiter = "\n";
		while ((pos = description.find(delimiter)) != std::string::npos) {
			token = description.substr(0, pos);

			cipher = adaptee->getEncryptedString(token);
			StringSource(cipher, true, new HexEncoder(new StringSink(HEX_encoded)));
			ss << HEX_encoded << endl;

			description.erase(0, pos + delimiter.length());
			cipher.clear();
			HEX_encoded.clear();
		}
		return ss.str();
	}

	virtual void generate_block_values() override {
		adaptee->generateKeyIVblocks();
	}

	virtual void write_encryption_additional_info(ofstream& out) override {
		out << adaptee->getKeyIVstring();
	}

	virtual void read_block_values(ifstream& in) override {
		adaptee->readKeyIVblocks(in);
	}

	virtual string get_item_info_string_to_read(string description) override {
		string cipher, original;
		StringSource ss(description, true, new HexDecoder(new StringSink(cipher)));
		original = adaptee->getDeencryptedString(cipher);
		return original;
	}

public:
	void set_encryption_adaptee(Encryption* pointer) { adaptee = pointer; }
};

AES_Encryption aes;
RC6_Encryption rc6;
Aria_Encryption aria;
Encryption encryption;
EncryptionAdapter enc_adapter;
NoEncryptionIO no_enc;
FileInputOutput* IO_pointer = &no_enc;

/////////////////////////////////=========================================================================================


//—Óı‡ÌËÚ¸ .txt
System::Void MainForm::toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ pathToSave;
	saveFileDialog1->DefaultExt = "*.txt";
	saveFileDialog1->Filter = "txt files |*.txt";

	if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
		pathToSave = saveFileDialog1->FileName;
		string path = getNormalString(pathToSave);
		IO_pointer->write_to_file(path, vlist);
	}
}

EncryptionAlgorithm* getCurrentAlgorithm() {
	switch (ENCRYPT_STATE) {
	case 1: return &aes;
	case 2: return &rc6;
	case 3: return &aria;
	default: return nullptr;
	}
}

//ŒÚÍ˚Ú¸ .txt
System::Void MainForm::toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ pathToRead;
		openFileDialog1->DefaultExt = "*.txt";
		openFileDialog1->Filter = "txt files |*.txt";

		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
			pathToRead = openFileDialog1->FileName;

			string path = getNormalString(pathToRead), type, buf;;
			ifstream in(path);
			int N = 0, encryptionType = 0;

			getline(in, buf); N = stoi(buf);

			getline(in, buf); encryptionType = stoi(buf);

			FileInputOutput* old_io = IO_pointer;
			EncryptionAlgorithm* old_enc_alg = getCurrentAlgorithm();

			switch (encryptionType) {
			case 0: {
				IO_pointer = &no_enc;
				break;
			}

			case 1: case 2:	case 3: {
				IO_pointer = &enc_adapter;
				enc_adapter.set_encryption_adaptee(&encryption);

				switch (encryptionType) {
				case 1: {
					encryption.set_encryption_algorithm(&aes);
					break;
				}
				case 2: {
					encryption.set_encryption_algorithm(&rc6);
					break;
				}
				case 3: {
					encryption.set_encryption_algorithm(&aria);
					break;
				}
				}

				break;
			}
			}

			IO_pointer->read_from_file(in, vlist, N);
			IO_pointer = old_io;
			encryption.set_encryption_algorithm(old_enc_alg);
			refreshList(listView1, this);
		}
	}
	catch (exception& e) {
		MessageBox::Show("This type of encryption is not supported!");
		vlist.clear();
	}
}

System::Void MainForm::toolStripComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int SelectedIndex = toolStripComboBox1->SelectedIndex;
	switch (SelectedIndex) {
		case 0: {
			ENCRYPT_STATE = 0;
			IO_pointer = &no_enc;
			break;
		}
		case 1:	case 2: case 3: {
			ENCRYPT_STATE = SelectedIndex;
			IO_pointer = &enc_adapter;
			enc_adapter.set_encryption_adaptee(&encryption);

			switch (ENCRYPT_STATE) {
			case 1: {
				encryption.set_encryption_algorithm(&aes);
				break;
			}
			case 2: {
				encryption.set_encryption_algorithm(&rc6);
				break;
			}
			case 3: {
				encryption.set_encryption_algorithm(&aria);
				break;
			}
			}
			break;
		}
	}
}