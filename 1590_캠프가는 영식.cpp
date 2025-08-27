#include <iostream>
#include <vector>

using namespace std;

class Bus
{
public:
	Bus(int d, int i, int c)
		:departure(d), interval(i), count(c)
	{
	};

	int departure;
	int interval;
	int count;
};

int main()
{
	int num;
	int arrivalTime;
	int departure, interval, count;
	int waitTime = INT32_MAX;
	vector<Bus> busList;
	cin >> num >> arrivalTime;
	while (num--)
	{
		cin >> departure >> interval >> count;
		busList.emplace_back(departure, interval, count);
	}
	for (Bus& bus : busList)
	{
		int time = 0;
		for (int i = 0; i < bus.count; i++)
		{
			if ((bus.count == 1 || i == 0) && arrivalTime <= bus.departure)
			{
				waitTime = min(waitTime, bus.departure - arrivalTime);
				break;
			}
			else if (i == bus.count - 1)
			{
				break;
			}
			else if (arrivalTime > bus.departure + i * bus.interval && arrivalTime <= bus.departure + (i + 1) * bus.interval)
			{
				waitTime = min(waitTime, bus.departure + (i + 1) * bus.interval - arrivalTime);
				break;
			}
		}
	}
	if (waitTime == INT32_MAX)
	{
		waitTime = -1;
	}
	cout << waitTime;
	return 0;
}