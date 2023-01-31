#ifndef EMSCRIPTEN_UPLOAD_FILE_H_INCLUDED
#define EMSCRIPTEN_UPLOAD_FILE_H_INCLUDED

// Based on emscripten-browser-file package by Armchair Software, licensed under MIT
// https://github.com/Armchair-Software/emscripten-browser-file

#include <string>
#include <emscripten.h>

namespace emscripten_browser_file {

using upload_handler = void(*)(std::string const&, std::string const&, std::string_view buffer, void*);

void upload(std::string const &accept_types, upload_handler callback, void *callback_data = nullptr);
void download(std::string const &filename, std::string const &mime_type, std::string_view buffer);
void down(std::string const &filename);

namespace {

extern "C" {

EMSCRIPTEN_KEEPALIVE int load_file_return(char const *filename, char const *mime_type, char *buffer, size_t buffer_size, upload_handler callback, void *callback_data);

}

}

}

#endif // EMSCRIPTEN_UPLOAD_FILE_H_INCLUDED
