package com.example.laboratory.designpattern.prototype;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.ArrayList;

@Getter
@Setter
@ToString
public class BookShelf {

    private ArrayList<Book> originBookShelf;

    public BookShelf() {
        originBookShelf = new ArrayList<>();
    }

    public void addBook(Book book) {
        originBookShelf.add(book);
    }

    // 생성자를 활용해 객체 복사 (Deep Copy)
    public BookShelf(BookShelf originBookShelf) {
        this.originBookShelf = new ArrayList<>();
        for (Book originBook : originBookShelf.getOriginBookShelf()) {
            this.originBookShelf.add(new Book(originBook));
        }
    }
}
