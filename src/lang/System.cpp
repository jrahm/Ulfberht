#include <ulfberht/lang/System.hpp>
#include <ulfberht/io/Handle.hpp>

using namespace io;

namespace lang {

Handle sterr_handle = Handle(2);
Handle stout_handle = Handle(1);
Handle stin_handle = Handle(0);

io::BaseOutput& System::out = stout_handle;
io::BaseInput& System::in = stin_handle;
io::BaseOutput& System::err = sterr_handle;

}
