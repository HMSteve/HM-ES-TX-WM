namespace as {

bool radiosleepflag = false;

class RadioSleep : public Alarm {

  
public:
  RadioSleep() : Alarm(0) {}
  virtual ~RadioSleep() {}

  virtual void trigger(AlarmClock& clock) {
    DPRINTLN("setting radio sleep flag");
    radiosleepflag=true;
  }

  virtual void setDelay(uint8_t seconds) {
    sysclock.cancel(*this);
    set(seconds2ticks(seconds));
    sysclock.add(*this);
  }

  virtual void stopDelay() {
    DPRINTLN("cancelling sleep delay");    
    sysclock.cancel(*this);
    radiosleepflag=false;
  }  
  
};

}
