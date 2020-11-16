package com.company;

import java.util.LinkedList;
import java.util.Scanner;

class Pair<T,U> {
    public final T t;
    public final U u;

    public Pair(T t, U u) {
        this.t= t;
        this.u= u;
    }
}

public class Main {

    public static boolean isNumeric(char str) {
        try {
            Double.parseDouble(String.valueOf(str));
            return true;
        } catch(NumberFormatException e){
            return false;
        }
    }

    public static  Boolean checkData(String data){
        for (int i=0;i<data.length();i++){
            if ((i ==0 || i == data.length() - 1) && !isNumeric(data.charAt(i))) {
                return false;
            }
            if (isNumeric(data.charAt(i)) | String.valueOf(data.charAt(i)).equals("+")
                    | String.valueOf(data.charAt(i)).equals("*") | String.valueOf(data.charAt(i)).equals("/") | String.valueOf(data.charAt(i)).equals("-")){
                continue;
            } else {
                return  false;
            }
        }
        return true;
    }

    public static Pair<LinkedList<Integer>, LinkedList<String>> parseData(String data){
        LinkedList<Integer> number = new LinkedList<Integer>();
        LinkedList<String> action = new LinkedList<String>();
        String timeNumber = "";
        for (int i=0;i<data.length();i++){
            if (!isNumeric(data.charAt(i))){
                action.add(String.valueOf(data.charAt(i)));
                if (timeNumber != "") {
                    number.add(Integer.valueOf(timeNumber));
                    timeNumber = "";
                }
            } else{
                timeNumber += String.valueOf(data.charAt(i));
            }
        }
        if (timeNumber != "") {
            number.add(Integer.valueOf(timeNumber));
            timeNumber = "";
        }
        return new Pair(number,action);
    }

    public static Pair<LinkedList<Integer>, LinkedList<String>> hardAction(LinkedList<Integer> number, LinkedList<String> action){
        Integer i = 0;
        Boolean check = true;
        while (check){
            if (action.get(i).equals("*")) {
                number.set(i,number.get(i)*number.get(i+1));
                number.remove(i+1);
                action.remove(i+1-1);
                i = 0;
            }else if (action.get(i).equals("/")) {
                number.set(i,number.get(i)/number.get(i+1));
                number.remove(i+1);
                action.remove(i+1-1);
                i = 0;
            }
            i += 1;
            if (action.size() <= i){
                break;
            }
        }
        return new Pair(number,action);
    }

    public static String simpleAction(LinkedList<Integer> number, LinkedList<String> action){
        Integer i = 0;

        while (!action.isEmpty()){
            if (action.get(i).equals("+")) {
                number.set(i,number.get(i)+number.get(i+1));
                number.remove(i+1);
                action.remove(i+1-1);
                i = 0;
            }else if (action.get(i).equals("-")) {
                number.set(i,number.get(i)-number.get(i+1));
                number.remove(i+1);
                action.remove(i+1-1);
                i = 0;
            }
        }
        return String.valueOf(number.get(0));
    }

    public static String action(String data){

        if (checkData(data)){
            Pair<LinkedList<Integer>, LinkedList<String>> parse = parseData(data);
            parse = hardAction(parse.t,parse.u);
            return simpleAction(parse.t,parse.u);
        }else {
            return "Не вырные входные данные";
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите уравнение: ");
        String data = in.nextLine();
        System.out.println(action(data));
    }
}