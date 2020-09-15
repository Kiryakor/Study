package com.example.demo.model;

import java.util.ArrayList;

public class MainModel {

    public static class DataMoney {
        public String href;
        public int price;
        public int count;
        public String name;

        public DataMoney(String href, int price, int count, String name) {
            this.href = href;
            this.price = price;
            this.count = count;
            this.name = name;
        }
    }

    ArrayList<DataMoney> dataMoneis = new ArrayList<>();

    public MainModel(){
        dataMoneis.add(new DataMoney("https://upload.wikimedia.org/wikipedia/ru/9/9d/1_euro._New_design.gif",75,1,"доллар"));
        dataMoneis.add(new DataMoney("https://c7.hotpng.com/preview/577/876/953/united-states-dollar-presidential-1-coin-program-dollar-coin-dollar.jpg",80,1,"евро"));
    }

    public void addData(DataMoney data){
        dataMoneis.add(data);
    }

    public void removeData(String name){
        dataMoneis.removeIf( i -> i.name.equals(name));
    }

    public int dataSize(){
        return dataMoneis.size();
    }

    public ArrayList<DataMoney> getData(){
        return dataMoneis;
    }
}