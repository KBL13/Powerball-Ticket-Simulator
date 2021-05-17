package com.company;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Main {

    //Builds a "mixed bag" with weighted numbers
    public static ArrayList<Integer> RandomizeNumbers(int[] input)
    {
        ArrayList<Integer> RandomizeNumbersList = new ArrayList<>();
        for (int i=0; i < input.length; i++)
        {
            for (int j=0; j < input[i]; j++)
            {
                RandomizeNumbersList.add(i+1);
            }
        }
        Collections.shuffle(RandomizeNumbersList);
        return RandomizeNumbersList;
    }

    //Generate powerball tickets based on weighted numbers being pulled randomly from the bag.
    public static ArrayList<Integer> TicketGeneration(int[] Number, int[] Powerball)
    {
        Random rand = new Random();
        ArrayList<Integer> Ticket = new ArrayList<>();
        int randomSelection;
        ArrayList<Integer> tempNumberList = RandomizeNumbers(Number);
        ArrayList<Integer> tempPowerballList = RandomizeNumbers(Powerball);
        for (int i=0; i < 5; i++)
        {
            randomSelection = rand.nextInt(IntStream.of(Number).sum());

            if(Ticket.isEmpty()) {
                Ticket.add(tempNumberList.get(randomSelection));
            } else {
                //Dupe Handling
                int tempPick = tempNumberList.get(randomSelection);
                boolean tempDupeFlag = false;
                for (int j=0; j<Ticket.size();j++)
                {
                    if(Ticket.get(j) == tempPick)
                    {
                        //System.out.println("Dupe Found:" + tempPick);
                        tempDupeFlag = true;
                    }
                }
                if (tempDupeFlag) {i = i-1;} else {Ticket.add(tempPick);}
            }

        }

        //Sort ticket from smallest to largest like a normal ticket
        Collections.sort(Ticket);

        //Powerball selection
        randomSelection = rand.nextInt(IntStream.of(Powerball).sum());
        Ticket.add(tempPowerballList.get(randomSelection));
        return Ticket;

    }
    public static void main(String[] args) {

        //Frequency data updated 05/12/21
	    //Index is relative to number frequency [0] = 1 picked 44 times historically
        int[] RegularNumbersFreq = {44,39,49,37,42,42,39,42,39,44,37,47,34,48,40,47,50,42,38,46,51,38,60,33,40,35,49,49,38,36,38,59,42,29,33,44,41,36,43,44,46,43,39,43,41,30,41,36,36,42,31,44,56,40,36,46,43,36,46,37,58,47,50,50,36,41,44,47,51};
	    int[] PowerballNumberFreq = {19,21,26,26,21,26,19,23,23,22,20,17,27,22,17,16,17,33,23,22,30,21,17,31,23,22};

	    //user input
        System.out.print("How many tickets would you like to print: ");
        Scanner s = new Scanner(System.in);
        int num = s.nextInt();

	    //user input tickets generated
	    for (int i=0; i < num; i++) {
            System.out.println(TicketGeneration(RegularNumbersFreq,PowerballNumberFreq).toString());
        }



    }
}
