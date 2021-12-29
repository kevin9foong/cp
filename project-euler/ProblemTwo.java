public class ProblemTwo { 
  public static void main(String[] args) {
    long limit = Long.parseLong(args[0]); 
    long minusSix = 2; 
    long minusThree = 8; 
    long sum = minusSix + minusThree;
    if (limit < 2) {
      sum = 0; 
    } else if (limit < 8) {
      sum = 2; 
    } else if (limit < 10) {
      sum = 8; 
    }

    long nextEven = 4 * minusThree + minusSix;  
    while (nextEven < limit) {
      sum += nextEven;
      minusSix = minusThree; 
      minusThree = nextEven; 
      nextEven = 4 * minusThree + minusSix;  
    }
    System.out.println(sum); 
  }
}
