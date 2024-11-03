package com.example.designpattern.singleton;

public class ConnectionPool {

    // 클래스 로딩 시점에 인스턴스를 한 번만 생성
    private static ConnectionPool instance = new ConnectionPool();

    // 클래스를 private으로 선언해 외부에서 직접 인스턴스를 생성하지 못함
    private ConnectionPool() {};

    // 외부에서 getInstance() 메소드를 통해 instance에 접근 가능
    public static ConnectionPool getInstance() {
        // 이미 초기화되어 있으므로 instance가 null인지 체크하는 로직은 사실 필요 없음
        if (instance == null) {
            // 실제로 도달하지 않음
            instance = new ConnectionPool();
        }

        return instance;
    }
}
