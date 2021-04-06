package hw4.com;

interface CarbonFootprint {
    public void testCarbonfootprint();
}
public class getCarbonFootprint {
    public static void main(String[] args){
        Building build = new Building();
        Car gofast = new Car();
        Bicycle bike = new Bicycle();

        build.testCarbonfootprint();
        gofast.testCarbonfootprint();
        bike.testCarbonfootprint();
    }
}
