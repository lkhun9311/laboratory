package com.example.laboratory.designpattern.builder;

import lombok.ToString;

public class Calzone extends Pizza {

    private final boolean sauceInside;

    public static class Builder extends Pizza.Builder {
        private boolean sauceInside = false;

        public Builder sauceInside() {
            sauceInside = true;
            return this;
        }

        @Override
        public Calzone build() {
            return new Calzone(this);
        }

        @Override
        protected Builder self() {
            return this;
        }
    }

    private Calzone(Builder builder) {
        super(builder);
        sauceInside = builder.sauceInside;
    }

    public String toString() {
        return "Calzone( "
                + "sauceInside=[" + sauceInside + "], "
                + "toppings=[" + toppings + "]"
                + " )";
    }
}
