// Student Name: Christopher Bell
// Program Name: Compute Grade From File
// Creation Date: Oct. 24, 2017
// Last Modified Date: Oct. 26, 2017
// CSCI Course: 325
// Grade Received: 100/100


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package finalprojecta2;

/**
 *
 * @author chrisbell
 */

import java.io.*;
import java.util.*;

public class Compute_GPA_From_File {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter the path of the file "
                + "you want to use: ");
        String path = in.nextLine();
        File file = new File(path);

        BufferedReader br = null;
        FileReader fr = null;
        FileWriter fw = null;

        ArrayList<Double> singleStudent = new ArrayList<>();
        String CurrentLine;
        Double classesTotal = 6.00;

        if (file.exists()){
            try {
                fr = new FileReader(file);
                fw = new FileWriter("gradedOutput.txt");
                br = new BufferedReader(fr);

                while ((CurrentLine = br.readLine()) != null) {
                    String splitLine[] = CurrentLine.split("\\s+");
                    String tempStudentID = splitLine[0];
                    String score1 = splitLine[1];
                    String score2 = splitLine[2];
                    String score3 = splitLine[3];
                    String score4 = splitLine[4];
                    String score5 = splitLine[5];
                    String score6 = splitLine[6];
                    String creditTemp = splitLine[7];
                    String GPATemp = splitLine[8];

                    /* Now parse the values to integers here */
                    Double studentID = Double.parseDouble(tempStudentID);
                    Double i1 = Double.parseDouble(score1);
                    Double i2 = Double.parseDouble(score2);
                    Double i3 = Double.parseDouble(score3);
                    Double i4 = Double.parseDouble(score4);
                    Double i5 = Double.parseDouble(score5);
                    Double i6 = Double.parseDouble(score6);
                    Double credit = Double.parseDouble(creditTemp);
                    Double GPA = Double.parseDouble(GPATemp);

                    Double totalPoints = 0.0;
                    totalPoints += GPACalc(i1);
                    totalPoints += GPACalc(i2);
                    totalPoints += GPACalc(i3);
                    totalPoints += GPACalc(i4);
                    totalPoints += GPACalc(i5);
                    totalPoints += GPACalc(i6);

                    GPA = totalPoints/classesTotal;

                    singleStudent.add(studentID);
                    singleStudent.add(i1);
                    singleStudent.add(i2);
                    singleStudent.add(i3);
                    singleStudent.add(i4);
                    singleStudent.add(i5);
                    singleStudent.add(i6);
                    singleStudent.add(credit);
                    singleStudent.add(GPA);

                    fw.write(singleStudent + "\n");

                    singleStudent.clear();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (br != null)
                        br.close();
                    if (fr != null)
                        fr.close();
                    if (fw != null)
                        fw.close();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }

        }
        else {
            System.out.println("Could not find file.");
        }
    }

    public static double GPACalc (double score){
        int runningtotal = 0;

        if (100 >= score && score >= 80)
            {runningtotal += 5;}
        else if (80 > score && score >= 70)
            {runningtotal += 4;}
        else if (70 > score && score >= 60)
            {runningtotal += 3;}
        else if (60 > score && score >= 50)
            {runningtotal += 2;}
        else if (50 > score && score >= 40)
            {runningtotal += 1;}
        else if (40 > score)
            {runningtotal += 0;}

        return runningtotal;
    }
}
