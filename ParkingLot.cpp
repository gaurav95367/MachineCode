//Design Multi level parking building
// 1) parking building have multple floors
// 2) each floor has multiple type of parking - small (bikes),medium(car),large(truck)
// 3) charge for small = 10 rs/hour  medium =50rs/hour large=100rs/hour
// 3) user can see all avilable slots of any type and can book they will get a bookingId in return
// 4) user can moveOut vechile and pay price at final gate
// 5) user can find thier vechile by giving bookingId

#include <bits/stdc++.h>	
using namespace std;

int globalClock;
enum SLOT_TYPE {
    SMALL,    // 0
    MEDIUM,  // 1
    LARGE    // 2
};

class Booking{
public:
	int bookingId;
	SLOT_TYPE slottype;
	string userId;
	int floorNumber;
	int slotId;
	int inTime;
};

class RateManager{
public:
	int getPerHourRate(SLOT_TYPE slotType){
		if(slotType == SLOT_TYPE::SMALL)
			return 10;
		if(slotType == SLOT_TYPE::MEDIUM)
			return 50;
		if(slotType == SLOT_TYPE::LARGE)
			return 100;
		return 100;
	}
}

class Floor{
public:
	vector< vector<bool> > slotsEmpty;	//slotsEmpty[0][9] = type 0 , 9th slot
	Floor(int numSmallSlots, numMediumSlots, numLargeSlots){
		slotsEmpty.resize(3);
		slotsEmpty[0].resize(numSmallSlots,true);
		slotsEmpty[0].resize(numMediumSlots,true);
		slotsEmpty[0].resize(numLargeSlots,true);
	}
};


class ParkingLot{
private:
	unordered_map<int,Booking> bookingMap;
	RateManager rm;
	vector<Floor> floorList;
public:

	ParkingLot(vector<int> numSmallSlots,vector<int> numMediumSlots,vector<int> numLargeSlots){
		int numFloors = numSmallSlots.size();
		for(int i=0;i<numFloors;i++){
			Floor f(numSmallSlots[i],numMediumSlots[i],numLargeSlots[i]);
			floorList.psuh_back(f);
		}
	}

	void showFreeSpots(SLOT_TYPE slotType){
		cout<<"for slotType="<<slotType<<" price per hour = "<<rm.getPerHourRate(slotType)<<endl;
		for(int i=0;i<floorList.size();i++){
			cout<<"Floor="<<i<<" spots=";
			for(int j=0;j<floorList[i].slotsEmpty[slotType].size();j++)
				if(floorList[i].slotsEmpty[slotType][j] == true)
					cout<<j<<" ";
			cout<<endl;			
		}
	}
	int bookFreeSpot(int floorNumber,int slotId,SLOT_TYPE slottype, string userId){
		//check if already booked or not

		floorList[floorNumber].slotsEmpty[slottype][slotId] = false;
		Booking b;
		b.bookingId = bookingMap.size();
		b.slottype = slottype;
		b.userId = userId;
		b.floorNumber = floorNumber;
	 	b.slotId = slotId;
		b.inTime = globalClock;

		bookingMap[b.bookingId] = b;
		cout<<"Booking done"<<endl;	
	}
	void moveOutVechile(int bookingId){
		if(bookingMap.find(bookingId) == bookingId.end()){
			cout<<"NOT FOUND"<<endl;
			return;
		}
		Booking b = bookingMap[bookingId];
		cout<<"Floor number = "<<b.floorNumber<<endl;
		cout<<"slotId  = "<<b.slotId<<endl;
		cout<<"inTime  = "<<b.inTime<<endl;
		cout<<"userId  = "<<b.userId<<endl;

		int timdiff = globalClock - b.inTime;
		int price = timdiff * rm.getPerHourRate(b.slottype);
		cout<<"Please pay "<<price<<endl;

		//empty the slot
		floorList[b.floorNumber].slotsEmpty[b.slottype][b.slotId] = true; 
	}

	void findMyVechile(int bookingId){
		if(bookingMap.find(bookingId) == bookingId.end()){
			cout<<"NOT FOUND"<<endl;
			return;
		}
		Booking b = bookingMap[bookingId];
		cout<<"Floor number = "<<b.floorNumber<<endl;
		cout<<"slotId  = "<<b.slotId<<endl;
		cout<<"inTime  = "<<b.inTime<<endl;
		cout<<"userId  = "<<b.userId<<endl;
	}
};


int main(){
    globalClock=0;

	return 0;
}
