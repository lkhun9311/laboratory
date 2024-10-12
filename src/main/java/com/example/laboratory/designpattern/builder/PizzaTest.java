package com.example.laboratory.designpattern.builder;

public class PizzaTest {
    public static void main(String[] args) {

        // NewYorkPizza의 Builder를 사용해 SMALL Size의 NewYorkPizza 객체 생성
        Pizza newYorkPizza = new NewYorkPizza.Builder(NewYorkPizza.Size.SMALL)
                .addTopping(Pizza.Topping.SAUSAGE) // SAUSAGE Topping 추가
                .addTopping(Pizza.Topping.ONION) // ONION Topping 추가
                .build(); // NewYorkPizza 객체 생성(build)

        // Calzone의 Builder를 사용해 CalzonePizza 객체 생성
        Pizza calzone = new Calzone.Builder()
                .addTopping(Pizza.Topping.HAM) // HAM Topping 추가
                .addTopping(Pizza.Topping.PEPPERONI) // PEPPERONI Topping 추가
                .sauceInside() // SauceInside 옵션 추가
                .build(); // CalzonePizza 객체 생성(build)

        System.out.println(newYorkPizza.toString());
        System.out.println(calzone.toString());
    }
}
