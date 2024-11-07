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

	class Touchpad
	{
		string type;
		double area;
	public:
		Touchpad()
		{
			type = "Default";
			area = 0.0;
		}
		Touchpad(const char* N, double A)
		{
			type = N;
			area = A;
		}
		void Show()
		{
			cout << "Touchpad type: " << type << "   Area " << area << endl;
		}
	};
	Touchpad touchpad;
public:
	Laptop():model(nullptr),cpu(nullptr,0), monitor(0,0), ram(nullptr), video(nullptr), battery(nullptr), mouse(nullptr) {}
	Laptop(const char* m, const char* manu, int g, int res, int d, RAM* r, VideoCard* v, Battery* b, Mouse* s, const char* t, double a) : cpu(manu,g), monitor(res, d), ram(r), video(v), battery(b), mouse(s), touchpad(t,a)
	{
		model = new char[strlen(m) + 1];
		strcpy_s(model, strlen(m) + 1, m);
	}
	~Laptop()
	{
		delete[] model;
	}

	void Show()
	{
		cout << "Laptop model: " << model << endl;
		cpu.Show();
		monitor.Show();
		ram->Show();
		video->Show();
		battery->Show();
		mouse->Show();
		touchpad.Show();
	}

};

int main()
{
	RAM myRAM{ 15.2, 3200 };
	VideoCard myVideo{ "RTX 3060", 3.6 };
	Battery myBattery{ "Battery 1", 3.7 };
	Mouse myMouse {"Mouse2", 3};
	Laptop myLaptop("Aorus", "Intel", 11, 1920, 15, &myRAM, &myVideo, &myBattery, &myMouse, "TouchPad2", 12.5);
	myLaptop.Show();

	return 0;
}
