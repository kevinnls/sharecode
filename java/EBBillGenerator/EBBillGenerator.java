import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;

class EBBillGenerator {
    public static Scanner scannerInput = new Scanner(System.in);
    public static HashMap<String,Customer> customerList = new HashMap<String,Customer>();

    private static float[][] domeTarrifArray = {{1.0f,0,100},{2.5f,101,200},{4.0f,201,500},{6.0f,501,Integer.MAX_VALUE}};
    private static float[][] commTarrifArray = {{2.0f,0,100},{4.50f,101,200},{6.0f,201,500},{7.0f,501,Integer.MAX_VALUE}};
    public static CustomerTarrif domesticTarrif = new CustomerTarrif(domeTarrifArray);
    public static CustomerTarrif commercialTarrif = new CustomerTarrif(commTarrifArray);

    public static void clearScreen() {
	System.out.print("\033[H\033[2J");
	System.out.flush();
    }


    public static void main (String[] args) {
	clearScreen();
	System.out.println("Welcome to EB Bill Generator");
	System.out.println("choose one:\n 1. new customer\nOR\n 2. returning cutomer");
	System.out.print("[ 1 OR 2 ] > ");
	if(scannerInput.nextInt() == 1){
	    clearScreen();
	    System.out.println("welcome, new customer");
	    Customer newCus = Customer.addCustomer();
	    customerList.put(newCus.number, newCus);
	    clearScreen();
	    System.out.println("generating bill...");
	    Customer.printBill(newCus);
	} else {
	    System.out.println("enter you customer number");
	    Customer currCus = customerList.get(scannerInput.nextLine());
	    System.out.println("generating bill...");
	    Customer.printBill(currCus);
	}
    }
}

class Customer {
    String name, number;
    CustomerType type;
    int prevReading, currReading;

    Customer(String cusNumber, String cusName, CustomerType cusType, int cusCurrReading, int cusPrevReading){
	this.number = cusNumber;
	this.name = cusName;
	this.type = cusType;
	this.prevReading = cusPrevReading;
	this.currReading = cusCurrReading;
    }

    private static float resolve(float tb){
	return tb >= 0.0f ? tb : 0.0f;
    }
    private static float genBillAmt(Customer cus){
	float uncalculatedUnits = (float)cus.currReading;
	float billedAmount = 0.0f;
	ArrayList<CustomerTarrif.TierTarrifRate> tarrif = cus.type.tarrif();
	for(int tier = 0; uncalculatedUnits > 0; tier++){
	    float tierBalance = resolve(uncalculatedUnits - (tarrif.get(tier).upperLimit - tarrif.get(tier).lowerLimit));
	    float tierUnits = uncalculatedUnits - tierBalance;
	    billedAmount += tierUnits * tarrif.get(tier).rate;
	    uncalculatedUnits = tierBalance;
	    System.out.println("at tier: " + tier + " for " + tierUnits + " with " + uncalculatedUnits + " left");
	}
	return billedAmount;
    }
    public static void printBill(Customer cus) {
	float billAmt = genBillAmt(cus);
	System.out.println("Hello, " + cus.name);
	System.out.println("Customer Number: " + cus.number);
	System.out.println("Customer type: " + cus.type.name());
	System.out.println("    Previous reading: " + cus.prevReading);
	System.out.println("    Current reading: " + cus.currReading);
	System.out.println("\n     Current Bill: " + billAmt);
    }
    public static Customer addCustomer() {
	Scanner scannerInput = new Scanner(System.in);
	System.out.println("enter your...");
	System.out.print("customer number: ");
	String number = scannerInput.nextLine();
	System.out.print("name: ");
	String name = scannerInput.nextLine();
	System.out.print("current reading: ");
	int currReading = scannerInput.nextInt();
	System.out.print("previous reading: ");
	int prevReading = scannerInput.nextInt();
	System.out.println("which category of customer are you?\n 1. a domestic customer\nOR\n 2. a commercial enterprise");
	System.out.print("[ 1 OR 2 ] > ");
	CustomerType type = scannerInput.nextInt() == 1 ? CustomerType.DOMESTIC : CustomerType.COMMERCIAL;

	return new Customer(number, name, type, currReading, prevReading);
    }
}

enum CustomerType {
    DOMESTIC(EBBillGenerator.domesticTarrif),
    COMMERCIAL(EBBillGenerator.commercialTarrif);

    private final ArrayList<CustomerTarrif.TierTarrifRate> tarrifValue;

    CustomerType(CustomerTarrif tarrif){
	tarrifValue = tarrif.get();
    }
    public ArrayList<CustomerTarrif.TierTarrifRate> tarrif(){
	return tarrifValue;
    }
}

class CustomerTarrif {
    ArrayList<TierTarrifRate> tarrifTier = new ArrayList<TierTarrifRate>();
    CustomerTarrif(float[][] rateArray){
	for(float[] row : rateArray){
	    tarrifTier.add(new TierTarrifRate(row[0],row[1],row[2]));
	}
    }
    public class TierTarrifRate {
	float rate, lowerLimit, upperLimit;
	public TierTarrifRate(float r, float l, float u){
	    this.rate = r;
	    this.lowerLimit = l;
	    this.upperLimit = u;
	}
    }    
    ArrayList<TierTarrifRate> get(){
	return this.tarrifTier;
    }
}

