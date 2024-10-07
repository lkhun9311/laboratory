package com.example.laboratory.designpattern.builder;

public class PizzaTest {
    public static void main(String[] args) {

        Pizza newYorkPizza = new NewYorkPizza.Builder(NewYorkPizza.Size.SMALL)
                .addTopping(Pizza.Topping.SAUSAGE)
                .addTopping(Pizza.Topping.ONION)
                .build();

        Pizza calzone = new Calzone.Builder()
                .addTopping(Pizza.Topping.HAM)
                .addTopping(Pizza.Topping.PEPPERONI)
                .sauceInside()
                .build();

        System.out.println(newYorkPizza.toString());
        System.out.println(calzone.toString());
    }
}
