package comp1406a2;

import java.util.Arrays;

/** Builds a sample database that you can use to help 
 with your own coding/debugging
 */
public class BuildDatabase{

	/** Build a small database of weather stations
	  * @param args is not used in this program
		*/
  public static void main(String[] args){
    // sample database
    WeatherDatabase db = new WeatherDatabase();

    // some WeatherStations
    WeatherStation[] stations = new WeatherStation[12];
    stations[0] = new WeatherStation("YOW-Airport", 1);
    stations[1] = new WeatherStation("Downtown", 2);
    stations[2] = new WeatherStation("Fallowfield-Railway-Station", 3);
    stations[3] = new WeatherStation("Test", 4);
    stations[4] =  new WeatherStation("Test", 5);
    stations[5] =  new WeatherStation("Test", 6);
    stations[6]= new WeatherStation("Blah", 17);

    
    int[] days = {1,2,2,2,4,7,11,20,30,32};
    double[] temps = {10.0, 11, 12, 10, 9.2, 28.1, 10.5, 20, 23, 24};

    // populate YOW with some weather reports
    // System.out.println("Building YOW WeatherStation");
    for(int i=0; i<days.length; i+=1){
      Temperature t = new Temperature(temps[i]);
      TimeStamp time = new TimeStamp(days[i],7, 15+i);
      WeatherReport wr = new WeatherReport(t, time, stations[0]);
      // System.out.println( "  " + wr.toString() );
      stations[0].addReport(wr);
    }

    // populate Down town weather station
    days = new int[]{1,2,7,8};
    temps = new double[]{12.1, 12.3, 15.2, 16.0, 17.0};
    // System.out.println("Building Downtown WeatherStation");
    for(int i=0; i<days.length; i+=1){
      Temperature t = new Temperature(temps[i], Scale.KELVIN);
      TimeStamp time = new TimeStamp(days[i],8, i);
      WeatherReport wr = new WeatherReport(t, time, stations[1]);
      // System.out.println( "  " + wr.toString() );
      stations[1].addReport(wr);
    }
    
    // populate Fallowfield
    days = new int[]{1,1,1,2,2,2,3,3,3,4,4,4,5,5,6,6,6,6,7,7,7,8,8,8};
    temps = new double[]{45, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-1,-1,
                         10,10,10,10,20,20,20,25,25,25};
    // System.out.println("Building Fallowfield WeatherStation");
    for(int i=0; i<days.length; i+=1){
      Temperature t = new Temperature(temps[i], Scale.FAHRENHEIT);
      TimeStamp time = new TimeStamp(days[i],12, 30+i);
      WeatherReport wr = new WeatherReport(t, time, stations[2]);
      // System.out.println( "  " + wr.toString() );
      stations[2].addReport(wr);
    }

    // days = new int[]{};
    // double[] tempser = new double[0];
    // // System.out.println("Building Fallowfield WeatherStation");
    // for(int i=0; i<days.length; i+=1){
    //   Temperature t = new Temperature(temps[i], Scale.FAHRENHEIT);
    //   TimeStamp time = new TimeStamp(days[i],12, 30+i);
    //   WeatherReport wr = new WeatherReport(t, time, stations[2]);
    //   System.out.println( "  " + wr.toString() );
    //   stations[3].addReport(wr);
    // }

    for (int i=0; i<stations.length; i++){
      db.addWeatherStation(stations[i]);
    }

    for (int h=0; h<50; h++){
      if(h<25){
        Temperature temper= new Temperature(h, Scale.FAHRENHEIT);
        TimeStamp timesta= new TimeStamp(h+2, h, h-2);
        WeatherReport were= new WeatherReport(temper, timesta, stations[3]);
        stations[3].addReport(were);
      }else{
        Temperature temper= new Temperature(h-50, Scale.KELVIN);
        TimeStamp timesta= new TimeStamp(h+2, h, h-2);
        WeatherReport were= new WeatherReport(temper, timesta, stations[3]);
        stations[3].addReport(were);  
      }
    }
    
    // for(int i=0; i<100; i+=1){
    //   WeatherStation blah=new WeatherStation("blah",i);
    //   db.addWeatherStation(blah);
    // }

    // for(int i=0; i<90; i+=1){
    //   WeatherStation blah=new WeatherStation("blah",i);
    //   db.removeWeatherStation(i);
    // }
    System.out.println(db.removeWeatherStation(2));

    System.out.println(Arrays.toString(db.getWeatherStations()));

    System.out.println(db.getMaxTemperature());
    System.out.println(db.getMaxTemperature(1));
    System.out.println(db.getMaxTemperature(2));
    System.out.println(db.getMaxTemperature(3));
    System.out.println(db.getMaxTemperature(4));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    db.addWeatherStation(stations[3]);
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.getMaxTemperature(5));
    System.out.println(db.getMaxTemperature(6));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    db.addWeatherStation(stations[4]);
    System.out.println(db.getMaxTemperature());
    System.out.println(db.removeWeatherStation(5));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.getMaxTemperature(7));
    System.out.println(db.getMaxTemperature(8));
    System.out.println(db.averageTemperature(1,8));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    db.addWeatherStation(stations[5]);
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.removeWeatherStation(1));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.averageTemperature(1,8));
    System.out.println(db.getMaxTemperature());
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.removeWeatherStation(2));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.averageTemperature(2,7));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.removeWeatherStation(3));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.averageTemperature(2,7));
    System.out.println(db.getMaxTemperature(8));
    db.addWeatherStation(stations[6]);
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.removeWeatherStation(4));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    System.out.println(db.removeWeatherStation(5));
    System.out.println(db.averageTemperature(4,10));
    System.out.println(Arrays.toString(db.getWeatherStations()));
    
    // System.out.println(Arrays.toString(stations[1].getReports()));
    // System.out.println(Arrays.toString(stations[2].getReports()));
    // System.out.println(Arrays.toString(stations[1].getReports()));
    // System.out.println(Arrays.toString(stations[0].getReports()));

  }



}
