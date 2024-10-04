package com.example.laboratory.designpattern.prototype;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.ArrayList;

@Getter
@Setter
@ToString
public class BookShelf implements Cloneable {

    private ArrayList<Book> originBookShelf;

    public BookShelf() {
        originBookShelf = new ArrayList<>();
    }

    public void addBook(Book book) {
        originBookShelf.add(book);
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        // 새로운 BookShelf 객체 생성, 초기화
        // Deep Copy 수행 (Default : Shallow Copy)
        BookShelf newBookShelf = new BookShelf();
        for (Book originBook : originBookShelf) {
            newBookShelf.addBook(new Book(originBook.getAuthor(), originBook.getTitle()));
        }

        return newBookShelf;
    }
}
