#ifndef client_h
#define client_h
#include "WProgram.h"	
#include "Print.h"
#include "Stream.h"
class Client : public Stream {

public:
  Client();
  Client(uint8_t);
  Client(uint8_t *, uint16_t);

  uint8_t status();
  uint8_t connect();
  virtual size_t write(uint8_t);
  virtual size_t write(const char *str);
  virtual size_t write(const uint8_t *buf, size_t size);
  virtual int available();
  virtual int read();
  virtual int read(uint8_t *buf, size_t size);
  virtual int peek();
  virtual void flush();
  void stop();
  uint8_t connected();
  uint8_t operator==(int);
  uint8_t operator!=(int);
  operator bool();

  friend class Server;

private:
  static uint16_t _srcport;
  uint8_t _sock;
  uint8_t *_ip;
  uint16_t _port;
};

#endif
