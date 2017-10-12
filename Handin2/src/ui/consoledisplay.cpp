#include "systemx/ui/consoledisplay.hpp"
#include "systemx/os/iostream.hpp"

namespace systemx {
namespace ui {
   
   os::ostream& ConsoleDisplay::get_cout() {
      return os::cout;
   }

}
}