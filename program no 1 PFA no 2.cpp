#include<iostream>
using namespace std;
void registerCustomer(string &customerName, int &customerID, string &customertype, int &installedMeters){
	int type;
	cout<<"Electricity Bill Management System for LESCO"<<endl;
	cout<<"========== CUSTOMER REGISTRATION =========="<<endl;
	cout<<"Enter your Name: ";
    cin>>customerName;
    cout<<"Enter your ID: ";
    cin>>customerID;
    cout<<"Select Customer Type "<<endl;
    cout<<"Type 1: Household "<<endl;
    cout<<"Type 2: Commercial "<<endl;
    cout<<"Enter your Customer Type: ";
    cin>>type;
    if(type==1){
    	customertype="Household";
	}
	else{
		customertype="Commercial";
	}
    cout<<"Enter Number of meters that already installed: ";
    cin>>installedMeters;	
}

int displayMenu(){
	int choice;
    cout<<"============ MAIN MENU ==========="<<endl;
    cout<<"1. Calculate Monthly Electricity Bill"<<endl;
    cout<<"2. Apply for New Electricity Connection"<<endl;
    cout<<"3. View Customer Details"<<endl;
    cout<<"4. Exit Program"<<endl;
    cout<<"Enter Your Choice what you want to do: ";
    cin>>choice;
    return choice;
}

float slabRate(int units, float perRateUnit[]){
	float rate;
  if(units>=1 && units<=100){
    rate=perRateUnit[0];
  }
  else if(units>=101 && units<=200){
  	rate=perRateUnit[1];
  }
  else if(units>=201 && units<=300){
    rate=perRateUnit[2];
  }
  else if(units>=301 && units<=400){
    rate=perRateUnit[3];
  }
  else if(units>=401 && units<=500){
    rate=perRateUnit[4];
  }
  else if(units>=501 && units<=600){
  	rate=perRateUnit[5];
  }
  else if(units>=601 && units<=700){
  	rate=perRateUnit[6];	
  }
  else if(units>700){
  rate=perRateUnit[7];
  }
  return units*rate;
}

float calculateGST(float bill){
    return bill*0.18;
}

float calculateIncomeTax(float bill, string customerType){
    if(customerType=="Household"){
        return bill*0.10;
    }
    else{
        return bill*0.15;
    }
}

float calculateElectricityDuty(float bill){
    return bill*0.015;
}

float calculateFixedCharges(int units){
	if(units<=300){
        return 0;
    }
    else if(units>=301 && units<=400){
        return 200;
    }
    else if(units>=401 && units<=500){
        return 400;
    }
    else if(units>=501 && units<=600){
        return 600;
    }
    else if(units>=601 && units<=700){
        return 800;
    }
    else if(units>700){
        return 1000;
    }
}

float tvFee(){
    return 35;
}

float meterRent(){
    return 250;
}

float newConnectionCharges(string customerType, int meterNumber){
    if(customerType=="Household"){
        if(meterNumber==1){
            return 2500;
        }
        else{
            return 5000;
        }
    }
    else{
        if(meterNumber==1){
            return 35000;
        }
        else{
            return 70000;
        }
    }
}

float properConnectionCost(){
    return 250000;
}

void displayFinalBill(float bill,float gst,float incomeTax,float duty,float fixedCharges,float rent,float tv,float totalBill){
 cout<<"\n========== FINAL BILL =========="<<endl;
    cout<<"Electricity Charges: "<<bill<<endl;
    cout<<"GST: "<<gst<<endl;
    cout<<"Income Tax: "<<incomeTax<<endl;
    cout<<"Electricity Duty: "<<duty<<endl;
    cout<<"Fixed Charges: "<<fixedCharges<<endl;
    cout<<"Meter Rent: "<<rent<<endl;
    cout<<"TV Fee: "<<tv<<endl;
    cout<<"Total Bill: "<<totalBill<<endl;
}

void displayCustomerDetails(string customerName, int customerID, string customertype, int installedMeters){
	cout<<"========== CUSTOMER DETAILS =========="<<endl;
    cout<<"Customer Name: "<<customerName<<endl;
    cout<<"Customer ID: "<<customerID<<endl;
    cout<<"Customer Type: "<<customertype<<endl;
    if(installedMeters==1){
        cout<<"Installed Meter: First Meter"<<endl;
    }
    else{
        cout<<"Installed Meter: Second Meter"<<endl;
    }
}
int main(){
    string customerName, customertype;
    int customerID, installedMeters, choice, units;
     registerCustomer(customerName, customerID, customertype,installedMeters);
    do{
    choice=displayMenu();
    switch(choice){
        case 1:{
            cout<<"Enter No of Units Consumed: ";
            cin>>units;
            float perRateUnit[8]={12.21, 14.53, 31.51,38.41, 41.62, 43.04,44.18, 49.10};
            float bill;
            float gst;
            float incomeTax;
            float duty;
            float fixedCharges;
            float rent;
            float tv;
            float totalBill;
            bill=slabRate(units, perRateUnit);
            gst=calculateGST(bill);
            incomeTax=calculateIncomeTax(bill, customertype);
            duty=calculateElectricityDuty(bill);
			fixedCharges=calculateFixedCharges(units);
            rent=meterRent();
			tv=tvFee();
            totalBill=bill+gst+incomeTax+duty+fixedCharges+rent+tv;
            displayFinalBill(bill,gst,incomeTax,duty,fixedCharges,rent,tv,totalBill);
        } 
            break;
        case 2:{
			int meterNumber;
            float meterCost, cableCost, securityCost;
            float additionalCharges, properCost, totalConnection;
            cout<<"Enter Meter Number (1 or 2): ";
            cin>>meterNumber;
            cout<<"Enter Meter Cost: ";
            cin>>meterCost;
            cout<<"Enter Cable Cost: ";
            cin>>cableCost;
            cout<<"Enter Security Cost: ";
            cin>>securityCost;
            additionalCharges=newConnectionCharges(customertype, meterNumber);
            properCost=properConnectionCost();
            totalConnection=meterCost+cableCost+securityCost+additionalCharges+properCost;
            cout<<"Total Connection Charges: "<<totalConnection<<endl;
        }
			break;
        case 3:
           displayCustomerDetails(customerName,customerID,customertype,installedMeters);
            break;
        case 4:
            cout<<"Program Exited Successfully"<<endl;
            break;
        default:
            cout<<"Invalid Choice"<<endl;
        }
} while(choice != 4);
}