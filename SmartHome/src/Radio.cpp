#include "../include/Devices/Radio.hpp"

namespace Jarvis {
  namespace Devices {
    Radio::Radio(const Device::name &name, const Connection::SerialPort::portName &portName, const Connection::SerialPort::portRate portRate)
    :Device(name, portName, portRate) {}
    
    Device::command Radio::makeRequest(const Device::command &command) const {
      return command; // name + "_" + cmd
    }
  }
}
