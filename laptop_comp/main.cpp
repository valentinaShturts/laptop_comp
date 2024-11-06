#include<iostream>
#include<string>
using namespace std;

class CPU
{
	string manufacturer;
	int generation;
public:
	CPU()
	{
		manufacturer = "Default";
		generation = 0;
	}
	CPU(const char* N, int G)
	{
		manufacturer = N;
		generation = G;
	}
	CPU(CPU& obj)
	{
		manufacturer = obj.manufacturer;
		generation = obj.generation;
	}
	void Show()
	{
		cout <<"CPU manufacturer: "<< manufacturer  << "   Gen " << generation << endl;
	}
};


class RAM
{
	double volume;
	int frequency;
public:
	RAM()
	{
		volume = 0.0;
		frequency = 0;
	}
	RAM(double N, int G)
	{
		volume = N;
		frequency = G;
	}
	RAM(RAM& obj)
	{
		volume = obj.volume;
		frequency = obj.frequency;
	}
	void Show()
	{
		cout << "RAM volume: " << volume << "   Frequency " << frequency << endl;
	}
};


class VideoCard
{
	string model;
	double volume;
public:
	VideoCard()
	{
		model = "Default";
		volume = 0.0;
	}
	VideoCard(const char* M, double N)
	{
		model = M;
		volume = N;
	}
	VideoCard(VideoCard& obj)
	{
		model = obj.model;
		volume = obj.volume;
	}
	void Show()
	{
		cout << "VideoCard model: " << model << "   Volume " << volume << endl;
	}
};


class Monitor
{
	int resolution;
	int diagonal;
public:
	Monitor()
	{
		resolution = 0;
		diagonal = 0;
	}
	Monitor(int R, int D)
	{
		resolution = R;
		diagonal = D;
	}
	Monitor(Monitor& obj)
	{
		resolution = obj.resolution;
		diagonal = obj.diagonal;
	}
	void Show()
	{
		cout << "Monitor resolution: " << resolution << "   Diagonal " << diagonal << endl;
	}
};


class Battery
{
	string model;
	double voltage;
public:
	Battery()
	{
		model = "Default";
		voltage = 0.0;
	}
	Battery(const char* M, double V)
	{
		model = M;
		voltage = V;
	}
	Battery(Battery& obj)
	{
		model = obj.model;
		voltage = obj.voltage;
	}
	void Show()
	{
		cout << "Battery model: " << model << "   Voltage " << voltage << endl;
	}
};

class Mouse
{
	string model;
	int buttonNumber;
public:
	Mouse()
	{
		model = "Default";
		buttonNumber = 2;
	}
	Mouse(const char* M, int V)
	{
		model = M;
		buttonNumber = V;
	}
	Mouse(Mouse& obj)
	{
		model = obj.model;
		buttonNumber = obj.buttonNumber;
	}
	void Show()
	{
		cout << "Mouse model: " << model << "   Number of buttons " << buttonNumber << endl;
	}
};



class Laptop
{
	char* model;
	CPU cpu;
	Monitor monitor;
	RAM* ram;
	VideoCard* video;
	Battery* battery;
	Mouse* mouse;

	class Vuz   // вложенный класс
	{
		string Name;
	public:
		Vuz()
		{
			Name = "Politex";
		}
		Vuz(const char* N)
		{
			Name = N;
		}
		void Show()
		{
			cout << Name << endl;
		}
	};
	Vuz vloj;
public:
	////  prototype 
	Student();
	Student(const char*, int, const char* vuz); // construct by 2 param
	~Student();

};
Student::Student()
{
	name = nullptr;
	age = 0;
}
Student::Student(const char* Name, int Age, const char* vuz) : vloj(vuz)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	age = Age;

}
Student::~Student()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	cout << "Destruct\n";

}