package com.Example;

class AverageCalculator<T extends Number> {
    T[] arr;
    AverageCalculator(T[] arr) {
        this.arr = arr.clone();
    }
    double getAverage() {
        double sum = 0;
        for(int i=0; i<arr.length; i++) {
            sum = sum + arr[i].doubleValue();
        }
        return sum / arr.length;
    }

    public static void main(String[] args) {
        Integer[] intarr = {1, 2, 3, 4, 5};
        AverageCalculator<Integer> intAvg = new AverageCalculator<>(intarr);

        Double[] doubarr = {1.1, 1.2, 1.3, 1.4, 1.5};
        AverageCalculator<Double> doubleAvg = new AverageCalculator<>(doubarr);

        System.out.println("Interger average: "+ intAvg.getAverage());
        System.out.print("Double average: "+ doubleAvg.getAverage());
    }
}
