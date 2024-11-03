package com.example.laboratory.designpattern.builder;

import lombok.ToString;

import java.util.EnumSet;
import java.util.Objects;
import java.util.Set;

@ToString
public abstract class Pizza {
    // 피자의 토핑을 열거하는 열거형(enum) 선언
    public enum Topping { HAM, MUSHROOM, ONION, PEPPERONI, SAUSAGE }

    // 피자의 토핑을 저장하는 불변집합(final Set)
    final Set<Topping> toppings;

    // Pizza 객체를 생성하기 위한 추상 정적 내부 클래스 Builder
    abstract static class Builder {
        // 피자의 토핑을 저장하기 위한 EnumSet. (Default. empty)
        EnumSet<Topping> toppings = EnumSet.noneOf(Topping.class);

        // 토핑을 추가하는 메소드. 추가하려는 토핑은 반드시 null이 아니어야 함.
        public Builder addTopping(Topping topping) {
            toppings.add(Objects.requireNonNull(topping));
            return self();
        }

        public Builder sauceInside() {
            return self();
        }

        // 최종적으로 Pizza 객체를 생성하는 추상 메소드
        abstract Pizza build();

        // 현재 객체의 참조를 반환하는 보호된 추상 메소드
        protected abstract Builder self();
    }

    // Builder를 통해 생성된 Pizza 객체의 생성자
    Pizza(Builder builder) {
        toppings = builder.toppings.clone();  // Builder의 토핑 집합 toppings를 복제해 할당
    }
}
