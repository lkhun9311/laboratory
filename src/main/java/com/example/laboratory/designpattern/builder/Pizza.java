package com.example.laboratory.designpattern.builder;

import lombok.ToString;

import java.util.EnumSet;
import java.util.Objects;
import java.util.Set;

@ToString
public abstract class Pizza {

    public enum Topping { HAM, MUSHROOM, ONION, PEPPERONI, SAUSAGE };
    final Set<Topping> toppings;

    abstract static class Builder {
        EnumSet<Topping> toppings = EnumSet.noneOf(Topping.class);

        public Builder addTopping(Topping topping) {
            toppings.add(Objects.requireNonNull(topping));
            return self();
        }

        public Builder sauceInside() {
            return self();
        }

        abstract Pizza build();

        protected abstract Builder self();
    }

    Pizza(Builder builder) {
        toppings = builder.toppings.clone();
    }
}
