package com.example.demo.helpers;

public class ConvertData {
    public  static int convertStringToInt(String value){
        int returnData;
        try {
            returnData = Integer.parseInt(value);
        }catch (NumberFormatException error){
            System.out.print(error.getLocalizedMessage());
            returnData = 0;
        }
        return  returnData;
    }
}
