#include<iostream>

using namespace std;

class Seat
{
private:
	string comfortability, seat_warmer_present;
public:
	void set_seat_data()
	{
		cout<<"Enter comfortability(Pleasant/ Comfy) : \n";
		cin>>comfortability;
		cout<<"Is seat warmer present? (yes/ no)\n";
		cin>>seat_warmer_present;
	}

	void show_seat_data()
	{
		cout<<"Seat comfortability is: "<<comfortability<<'\n';
		cout<<"Seat warmer present: "<<seat_warmer_present<<'\n';
	}
};

class Wheel
{
private:
	float radius;
public:
	void set_wheel_data()
	{
		cout<<"Enter wheel radius: ";
		cin>>radius;
	}
	void show_wheel_data()
	{
		cout<<"Wheel radius = "<<radius<<'\n';
	}

	float get_rad()
	{
	    return radius;
	}
};

class Engine
{
private:
    float max_fuel_rate, max_energy_rate, avg_rpm;

public:
    void set_engine_data ()
    {
        cout<<"Enter maximum fuel consumption rate: ";
        cin>>max_fuel_rate;
        cout<<"Enter maximum energy production rate: ";
        cin>>max_energy_rate;
        cout<<"Enter average rpm: ";
        cin>>avg_rpm;
    }

    void show_engine_data ()
    {
        cout<<"Maximum fuel consumption rate: "<<max_fuel_rate<<'\n';
        cout<<"Maximum energy production rate: "<<max_energy_rate<<'\n';
        cout<<"Average RPM: "<<avg_rpm<<endl;
    }

    float get_avg_rpm()
    {
        return avg_rpm;
    }
};

class Door
{
private:
    string opening_mode;

public :
   void set_door_data ()
   {
       cout<<"How the door opens (sideways/ upward): ";
       cin>>opening_mode;
   }

   void show_door_data ()
   {
       cout<<"Door opens: "<<opening_mode<<endl;
   }

};

class Truck
{
private:
	float max_acc, fuel_cap, load_cap;
	Seat st[2];
	Wheel w[6];
	Engine eng;
	Door d[2];
public:
	void set_truck_data()
	{
		for(int i=0; i<2; i++)
			st[i].set_seat_data();
		for(int i=0; i<6; i++)
			w[i].set_wheel_data();
		for(int i=0; i<2; i++)
			d[i].set_door_data();

		eng.set_engine_data();

		cout<<"Enter maximum acceleration: ";
        cin>>max_acc;

        cout<<"Enter fuel cap: ";
        cin>>fuel_cap;

        cout<<"Enter load cap: ";
        cin>>load_cap;

	}

	void show_truck_data()
	{
		for(int i=0; i<2; i++)
			st[i].show_seat_data();
		for(int i=0; i<6; i++)
			w[i].show_wheel_data();
		for(int i=0; i<2; i++)
			d[i].show_door_data();

		eng.show_engine_data();

		cout<<"Maximum acceleration: "<<max_acc<<'\n';
        cout<<"Fuel capacity: "<<fuel_cap<<'\n';
        cout<<"Load capacity: "<<load_cap<<'\n';
	}

	void calc_avg_speed()
	{
	    float ans = w[0].get_rad() * 2* 3.1416 * eng.get_avg_rpm() / 60;
	    cout<<"Average speed = "<<ans<<" meter/second\n";
	}
};
int main()
{
	Truck tr1;

	tr1.set_truck_data();

	tr1.show_truck_data();

	tr1.calc_avg_speed();
	return 0;
}
