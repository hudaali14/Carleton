package comp1406a2;


  /** A weather station keeps a collection of weather reports.
    * The actual weather station it models will make temperature
    * observations which provides the data for the reports.
    *
    * A weather station only needs to remember the last 10
    * reports added to it (in the order that they are added),
    * in addition to the report with the highest temperature that
    * has ever been and recorded/added to this weather station.
    * That is, it only needs to store 11 weather reports in total.
    *
    * Notes: The highest ever temperature record might be one of the
    *        last 10 added reports but it also might not.
    *        You must store the last 10 reports in an array.
    *        The higherst ever temperature report does not need to be
    *        sotred in this array (unless it was one of the last 10).
    */
  public class WeatherStation{

  /* --------------------------------------------------------------------------/
  /* --------------------------------------------------------------------------/
  /* ----------------------------------------------------- */
  /*                                                       */
  /* BEGIN  --  do NOT change anything until the end of    */
  /*            this block of attributes, constructor and  */
  /*            and methods                                */
  /*                                                       */
  /* ----------------------------------------------------- */

    /** The name of this weather station */
    protected final String name;

    /** The id number of this weather station. Should be unique. */
    protected final int    id;

    /** Initializes this weather station's name and id  */
    public WeatherStation(String nameOfStation, int idOfStation){
      this.name = nameOfStation;
      this.id   = idOfStation;
    }

    /** Getter for this weather station's name
     * @return the name of this weather station
     */
    public String getName(){ return this.name;  }

    /** Getter for this weather station's id number
     * @return the ID of this weather station
     */
    public int    getID(){ return this.id; }

    /** Creates a weather report
     * @param temperature is a valid temperature object correspinding to
     *                    an obervation at this weather station.
     * @param time is the time that the temoerature was recorded.
     * @return a weather report for this weather station recording
     *         the temperature and time of when the obervation was made.
     */
    public WeatherReport makeReport(Temperature temperature, TimeStamp time){
      return new WeatherReport(temperature, time, this);
    }

    /** A nice String representation of a weather station object */
    @Override
    public String toString(){
      return this.name + " [id:" + this.id + "]";
    }
  /* ----------------------------------------------------- */
  /*                                                       */
  /* END - complete the methods below these comments       */
  /*                                                       */
  /* ----------------------------------------------------- */
  /* --------------------------------------------------------------------------/*
  /* --------------------------------------------------------------------------/** */


    //creates array to hold last 10 weather reports and highest temp ever
    private WeatherReport[] reports= new WeatherReport[11];

    //holds highest temp by weather station
    private WeatherReport highest_ever= null;
    
    /** Adds a report to the station.
     *
     * @param report is a WeatherReport to be added to this WeatherStation
     * @return this WeatherStation. (Do NOT alter the return statement of this
     *         method.)
     *
     */
    public WeatherStation addReport(WeatherReport report){

        //moves all items in the array one index over
        for(int index=9; index>0; index--){
            if (index!=0){
                reports[index]=reports[index-1];
            }
        }

        //saves the newest report to the first element of the array
        reports[0]=report;

        //the last element of the array holdest the highest temp, so if it null it saves the newest report added and makes highest temp to that
        if (reports[10]==null){
            reports[10]=report;
            highest_ever=report;

        //loops through reports and makes the report with the highest temp at the last index in the array 
        }else{
            for(WeatherReport y: reports){
                reports[10]=reports[0];
                if (y!=null){
                    if(Compare.compare(y.temperature, reports[10].temperature)==1){
                        reports[10]=y;
                    }
                }
            }
        }

        //if newest report is greater than highest saves it as highest ever
        if(Compare.compare(report.temperature, highest_ever.temperature)==1){
            highest_ever=report;
        }
        return this;  // do NOT alter the return statement
    } 


      /** Returns the most recently added report.
        *
        *
        * @return the most recently added WeatherReport to this weatherstation.
        *         If no reports have ever been added then returns null.
        */
    public WeatherReport getMostRecentReport(){

        //if there's nothing in the report you can't return the most recent so returns null
        if (reports.length==0){
            return null;
        }

        //most recent report added is at the first index
        WeatherReport recent=reports[0];
        return recent;
    }


    /** Returns the last 10 weather getReports added to this weather station.
     * <p>
     * If there haven't been 10 reports added then return as many as has been added.
     *
     * @return an array of the last 10 added WeatherReports (in the order
     *         that they were added). The most recently added report is the
     *         first element in the array.
     *         If there has been less than 10 reports added to this
     *         weatherstation, then returns as many reports as there is.
     *         The returned array must be the same size as the number of
     *         reports returned.
     */
    public WeatherReport[] getReports(){

        //if there's nothing in the report you can't return the most recent so returns null
        if (reports.length==0){
          return null;
        }
        
        //creates array to hold last 10 reports
        WeatherReport[] last= new WeatherReport[0];
            for (int x=0; x<reports.length-1; x++){

                //if the report at the index is not equal to null
                if (reports[x]!=null){

                    //a temp array to hold the reports 
                    WeatherReport[] temp= new WeatherReport[last.length+1];

                    //an index 
                    int index1=0;

                    //copys all the reports from temp array to last array
                    for (WeatherReport w : last){
                        temp[index1]=last[index1];
                        index1++;
                    }

                    //saves item from reports at index x to temp at index1
                    temp[index1]=reports[x];

                    //make the last array equal to temp array
                    last=temp;
                }
            }
        return last;
    }


    /** Returns a weather report with highest recorded temperature
     * of any report ever added to this WeatherStation.  If there have been
     * multiple reports with the same highest temperature, the most recently
     * added report is returned,.
     *
     * @return a WeatherReport that has the highest recorded temperature
     *         of any report ever added to this WeatherStation. Returns
     *         null if no report has ever been added to this weatherstation.
     */
    public WeatherReport getReportWithMaxTemp(){

        //return the highest temp of a weather station
        return this.highest_ever;
    }
}
