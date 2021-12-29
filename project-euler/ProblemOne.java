import java.lang.*; 

public class ProblemOne {
  public static void main(String[] args) {
    int range = Integer.parseInt(args[0]); 
    System.out.println(getSum(range)); 
  }

  public static int getSum(int range) { 
    int upperRange = range; 
    int numberOfMultiplesOfThree =((upperRange - 1)/3);  	  
    int numberOfMultiplesOfFive = ((upperRange - 1)/5);  	  
    int numberOfMultiplesOfFifteen = ((upperRange - 1)/15);
		
    // by factoring and then Gaussian addition 
    int sumOfThrees = ((1 + numberOfMultiplesOfThree) * numberOfMultiplesOfThree) / 2 * 3; 
    int sumOfFives = ((1 + numberOfMultiplesOfFive) *  numberOfMultiplesOfFive) / 2 * 5; 
    int sumOfFifteens = ((1 + numberOfMultiplesOfFifteen) * numberOfMultiplesOfFifteen) / 2 * 15; 

    // apply inclusion-exclusion principle 
    return sumOfThrees + sumOfFives - sumOfFifteens;  
  }
}
