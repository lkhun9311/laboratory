package com.example.laboratory.designpattern.prototype;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@AllArgsConstructor
public class Book {

    private String author;
    private String title;

    // 생성자를 활용해 객체 복사
    public Book(Book originBook) {
        this.author = originBook.author;
        this.title = originBook.title;
    }
}
