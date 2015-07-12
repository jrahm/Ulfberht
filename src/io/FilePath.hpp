#ifndef SRC_IO_FILE_
#define SRC_IO_FILE_

/*
 * Author: jrahm
 * created: 2015/06/08
 * File.hpp: <description>
 */

#include <string>

#include <ulfberht/io/BaseOutput.hpp>
#include <ulfberht/io/BaseInput.hpp>
#include <ulfberht/lang/Maybe.hpp>

#include <ulfberht/lang/Exception.hpp>

namespace io {

class FilePath {
public:
    /**
     * Construct a file path.
     */
    FilePath(const std::string& path);

    bool exists() const;

    uptr<BaseOutput> getOutputStream();
    uptr<BaseInput> getInputStream();

    FilePath operator/(const FilePath& oth);

    static FilePath join(const char* path, ...);

private:
    std::string path;
};

}

#endif /* SRC_IO_FILE_ */
