#include <string.h>
#include "mlvalues.h"
#include "alloc.h"
#include "memory.h"
#include "raylib.h"

static inline value Val_string(const char *s)
{
    int len = strlen(s);
    value res = alloc_string(len);
    bcopy(s, &Byte(res, 0), len);
    return res;
}

static inline value Val_colour(Color c)
{
    return Val_int(*(int*)&c);
}

static inline Color Colour_val(value v)
{
    int c = Int_val(v);
    return *(Color*)&c;
}

static inline value Val_double(double x)
{
    value res = alloc_string(8);
    Store_double_val(res, x);
    return res;
}

static inline value Val_vector2(Vector2 v)
{
    value rec = alloc_tuple(2);
    modify(&Field(rec, 0), copy_double(v.x));
    modify(&Field(rec, 1), copy_double(v.y));
    return rec;
}

static inline Vector2 Vector2_val(value v)
{
    Vector2 vec = {
       .x = Double_val(Field(v, 0)),
       .y = Double_val(Field(v, 1)),
    };
    return vec;
}
static inline value Val_rectangle(Rectangle rect)
{
    value rec = alloc_tuple(4);
    modify(&Field(rec, 0), copy_double(rect.height));
    modify(&Field(rec, 1), copy_double(rect.width));
    modify(&Field(rec, 2), copy_double(rect.x));
    modify(&Field(rec, 3), copy_double(rect.y));
    return rec;
}

static inline Rectangle Rectangle_val(value v)
{
    Rectangle rect = {
       .height = Double_val(Field(v, 0)),
       .width  = Double_val(Field(v, 1)),
       .x      = Double_val(Field(v, 2)),
       .y      = Double_val(Field(v, 3)),
    };
    return rect;
}
static inline value Val_image(Image i)
{
    value rec = alloc_tuple(5);
    modify(&Field(rec, 0), (value)i.data);
    modify(&Field(rec, 1), Val_int(i.format));
    modify(&Field(rec, 2), Val_int(i.height));
    modify(&Field(rec, 3), Val_int(i.mipmaps));
    modify(&Field(rec, 4), Val_int(i.width));
    return rec;
}

static inline Image Image_val(value v)
{
    Image img = {
       .data    = (void*)(Field(v, 0)),
       .format  = Int_val(Field(v, 1)),
       .height  = Int_val(Field(v, 2)),
       .mipmaps = Int_val(Field(v, 3)),
       .width   = Int_val(Field(v, 4)),
    };
    return img;
}
static inline value Val_texture(Texture2D t)
{
    value rec = alloc_tuple(5);
    modify(&Field(rec, 0), Val_int(t.format));
    modify(&Field(rec, 1), Val_int(t.height));
    modify(&Field(rec, 2), Val_int(t.id));
    modify(&Field(rec, 3), Val_int(t.mipmaps));
    modify(&Field(rec, 4), Val_int(t.width));
    return rec;
}

static inline Texture2D Texture_val(value v)
{
    Texture2D tex = {
       .format  = Int_val(Field(v, 0)),
       .height  = Int_val(Field(v, 1)),
       .id      = Int_val(Field(v, 2)),
       .mipmaps = Int_val(Field(v, 3)),
       .width   = Int_val(Field(v, 4)),
    };
    return tex;
}

value raylib_InitWindow(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    const char * _title = String_val(Field(args, 2));
    InitWindow(_width, _height, _title);
    return Val_unit;
}

value raylib_CloseWindow(value unit)
{
    CloseWindow();
    return Val_unit;
}

value raylib_WindowShouldClose(value unit)
{
    bool result = WindowShouldClose();
    return Val_bool(result);
}

value raylib_IsWindowReady(value unit)
{
    bool result = IsWindowReady();
    return Val_bool(result);
}

value raylib_IsWindowFullscreen(value unit)
{
    bool result = IsWindowFullscreen();
    return Val_bool(result);
}

value raylib_IsWindowHidden(value unit)
{
    bool result = IsWindowHidden();
    return Val_bool(result);
}

value raylib_IsWindowMinimized(value unit)
{
    bool result = IsWindowMinimized();
    return Val_bool(result);
}

value raylib_IsWindowMaximized(value unit)
{
    bool result = IsWindowMaximized();
    return Val_bool(result);
}

value raylib_IsWindowFocused(value unit)
{
    bool result = IsWindowFocused();
    return Val_bool(result);
}

value raylib_IsWindowResized(value unit)
{
    bool result = IsWindowResized();
    return Val_bool(result);
}

value raylib_IsWindowState(value arg)
{
    unsigned int _flag = Long_val(arg);
    bool result = IsWindowState(_flag);
    return Val_bool(result);
}

value raylib_SetWindowState(value arg)
{
    unsigned int _flags = Long_val(arg);
    SetWindowState(_flags);
    return Val_unit;
}

value raylib_ClearWindowState(value arg)
{
    unsigned int _flags = Long_val(arg);
    ClearWindowState(_flags);
    return Val_unit;
}

value raylib_ToggleFullscreen(value unit)
{
    ToggleFullscreen();
    return Val_unit;
}

value raylib_ToggleBorderlessWindowed(value unit)
{
    ToggleBorderlessWindowed();
    return Val_unit;
}

value raylib_MaximizeWindow(value unit)
{
    MaximizeWindow();
    return Val_unit;
}

value raylib_MinimizeWindow(value unit)
{
    MinimizeWindow();
    return Val_unit;
}

value raylib_RestoreWindow(value unit)
{
    RestoreWindow();
    return Val_unit;
}

value raylib_SetWindowIcon(value arg)
{
    Image _image = Image_val(arg);
    SetWindowIcon(_image);
    return Val_unit;
}

/*
value raylib_SetWindowIcons(value args)
{
    Image * _images = UNKNOWN(Field(args, 0));
    int _count = Int_val(Field(args, 1));
    SetWindowIcons(_images, _count);
    return Val_unit;
}
*/

value raylib_SetWindowTitle(value arg)
{
    const char * _title = String_val(arg);
    SetWindowTitle(_title);
    return Val_unit;
}

value raylib_SetWindowPosition(value args)
{
    int _x = Int_val(Field(args, 0));
    int _y = Int_val(Field(args, 1));
    SetWindowPosition(_x, _y);
    return Val_unit;
}

value raylib_SetWindowMonitor(value arg)
{
    int _monitor = Int_val(arg);
    SetWindowMonitor(_monitor);
    return Val_unit;
}

value raylib_SetWindowMinSize(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    SetWindowMinSize(_width, _height);
    return Val_unit;
}

value raylib_SetWindowMaxSize(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    SetWindowMaxSize(_width, _height);
    return Val_unit;
}

value raylib_SetWindowSize(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    SetWindowSize(_width, _height);
    return Val_unit;
}

value raylib_SetWindowOpacity(value arg)
{
    float _opacity = Double_val(arg);
    SetWindowOpacity(_opacity);
    return Val_unit;
}

value raylib_SetWindowFocused(value unit)
{
    SetWindowFocused();
    return Val_unit;
}

/*
value raylib_GetWindowHandle(value unit)
{
    void * result = GetWindowHandle();
    return UNKNOWN(result);
}
*/

value raylib_GetScreenWidth(value unit)
{
    int result = GetScreenWidth();
    return Val_int(result);
}

value raylib_GetScreenHeight(value unit)
{
    int result = GetScreenHeight();
    return Val_int(result);
}

value raylib_GetRenderWidth(value unit)
{
    int result = GetRenderWidth();
    return Val_int(result);
}

value raylib_GetRenderHeight(value unit)
{
    int result = GetRenderHeight();
    return Val_int(result);
}

value raylib_GetMonitorCount(value unit)
{
    int result = GetMonitorCount();
    return Val_int(result);
}

value raylib_GetCurrentMonitor(value unit)
{
    int result = GetCurrentMonitor();
    return Val_int(result);
}

value raylib_GetMonitorPosition(value arg)
{
    int _monitor = Int_val(arg);
    Vector2 result = GetMonitorPosition(_monitor);
    return Val_vector2(result);
}

value raylib_GetMonitorWidth(value arg)
{
    int _monitor = Int_val(arg);
    int result = GetMonitorWidth(_monitor);
    return Val_int(result);
}

value raylib_GetMonitorHeight(value arg)
{
    int _monitor = Int_val(arg);
    int result = GetMonitorHeight(_monitor);
    return Val_int(result);
}

value raylib_GetMonitorPhysicalWidth(value arg)
{
    int _monitor = Int_val(arg);
    int result = GetMonitorPhysicalWidth(_monitor);
    return Val_int(result);
}

value raylib_GetMonitorPhysicalHeight(value arg)
{
    int _monitor = Int_val(arg);
    int result = GetMonitorPhysicalHeight(_monitor);
    return Val_int(result);
}

value raylib_GetMonitorRefreshRate(value arg)
{
    int _monitor = Int_val(arg);
    int result = GetMonitorRefreshRate(_monitor);
    return Val_int(result);
}

value raylib_GetWindowPosition(value unit)
{
    Vector2 result = GetWindowPosition();
    return Val_vector2(result);
}

value raylib_GetWindowScaleDPI(value unit)
{
    Vector2 result = GetWindowScaleDPI();
    return Val_vector2(result);
}

value raylib_GetMonitorName(value arg)
{
    int _monitor = Int_val(arg);
    const char * result = GetMonitorName(_monitor);
    return Val_string(result);
}

value raylib_SetClipboardText(value arg)
{
    const char * _text = String_val(arg);
    SetClipboardText(_text);
    return Val_unit;
}

value raylib_GetClipboardText(value unit)
{
    const char * result = GetClipboardText();
    return Val_string(result);
}

value raylib_GetClipboardImage(value unit)
{
    Image result = GetClipboardImage();
    return Val_image(result);
}

value raylib_EnableEventWaiting(value unit)
{
    EnableEventWaiting();
    return Val_unit;
}

value raylib_DisableEventWaiting(value unit)
{
    DisableEventWaiting();
    return Val_unit;
}

value raylib_ShowCursor(value unit)
{
    ShowCursor();
    return Val_unit;
}

value raylib_HideCursor(value unit)
{
    HideCursor();
    return Val_unit;
}

value raylib_IsCursorHidden(value unit)
{
    bool result = IsCursorHidden();
    return Val_bool(result);
}

value raylib_EnableCursor(value unit)
{
    EnableCursor();
    return Val_unit;
}

value raylib_DisableCursor(value unit)
{
    DisableCursor();
    return Val_unit;
}

value raylib_IsCursorOnScreen(value unit)
{
    bool result = IsCursorOnScreen();
    return Val_bool(result);
}

value raylib_ClearBackground(value arg)
{
    Color _color = Colour_val(arg);
    ClearBackground(_color);
    return Val_unit;
}

value raylib_BeginDrawing(value unit)
{
    BeginDrawing();
    return Val_unit;
}

value raylib_EndDrawing(value unit)
{
    EndDrawing();
    return Val_unit;
}

/*
value raylib_BeginMode2D(value arg)
{
    Camera2D _camera = UNKNOWN(arg);
    BeginMode2D(_camera);
    return Val_unit;
}
*/

value raylib_EndMode2D(value unit)
{
    EndMode2D();
    return Val_unit;
}

/*
value raylib_BeginMode3D(value arg)
{
    Camera3D _camera = UNKNOWN(arg);
    BeginMode3D(_camera);
    return Val_unit;
}
*/

value raylib_EndMode3D(value unit)
{
    EndMode3D();
    return Val_unit;
}

/*
value raylib_BeginTextureMode(value arg)
{
    RenderTexture2D _target = UNKNOWN(arg);
    BeginTextureMode(_target);
    return Val_unit;
}
*/

value raylib_EndTextureMode(value unit)
{
    EndTextureMode();
    return Val_unit;
}

/*
value raylib_BeginShaderMode(value arg)
{
    Shader _shader = UNKNOWN(arg);
    BeginShaderMode(_shader);
    return Val_unit;
}
*/

value raylib_EndShaderMode(value unit)
{
    EndShaderMode();
    return Val_unit;
}

value raylib_BeginBlendMode(value arg)
{
    int _mode = Int_val(arg);
    BeginBlendMode(_mode);
    return Val_unit;
}

value raylib_EndBlendMode(value unit)
{
    EndBlendMode();
    return Val_unit;
}

value raylib_BeginScissorMode(value args)
{
    int _x = Int_val(Field(args, 0));
    int _y = Int_val(Field(args, 1));
    int _width = Int_val(Field(args, 2));
    int _height = Int_val(Field(args, 3));
    BeginScissorMode(_x, _y, _width, _height);
    return Val_unit;
}

value raylib_EndScissorMode(value unit)
{
    EndScissorMode();
    return Val_unit;
}

/*
value raylib_BeginVrStereoMode(value arg)
{
    VrStereoConfig _config = UNKNOWN(arg);
    BeginVrStereoMode(_config);
    return Val_unit;
}
*/

value raylib_EndVrStereoMode(value unit)
{
    EndVrStereoMode();
    return Val_unit;
}

/*
value raylib_LoadVrStereoConfig(value arg)
{
    VrDeviceInfo _device = UNKNOWN(arg);
    VrStereoConfig result = LoadVrStereoConfig(_device);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadVrStereoConfig(value arg)
{
    VrStereoConfig _config = UNKNOWN(arg);
    UnloadVrStereoConfig(_config);
    return Val_unit;
}
*/

/*
value raylib_LoadShader(value args)
{
    const char * _vsFileName = String_val(Field(args, 0));
    const char * _fsFileName = String_val(Field(args, 1));
    Shader result = LoadShader(_vsFileName, _fsFileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadShaderFromMemory(value args)
{
    const char * _vsCode = String_val(Field(args, 0));
    const char * _fsCode = String_val(Field(args, 1));
    Shader result = LoadShaderFromMemory(_vsCode, _fsCode);
    return UNKNOWN(result);
}
*/

/*
value raylib_IsShaderValid(value arg)
{
    Shader _shader = UNKNOWN(arg);
    bool result = IsShaderValid(_shader);
    return Val_bool(result);
}
*/

/*
value raylib_GetShaderLocation(value args)
{
    Shader _shader = UNKNOWN(Field(args, 0));
    const char * _uniformName = String_val(Field(args, 1));
    int result = GetShaderLocation(_shader, _uniformName);
    return Val_int(result);
}
*/

/*
value raylib_GetShaderLocationAttrib(value args)
{
    Shader _shader = UNKNOWN(Field(args, 0));
    const char * _attribName = String_val(Field(args, 1));
    int result = GetShaderLocationAttrib(_shader, _attribName);
    return Val_int(result);
}
*/

/*
value raylib_SetShaderValue(value args)
{
    Shader _shader = UNKNOWN(Field(args, 0));
    int _locIndex = Int_val(Field(args, 1));
    const void * _value = UNKNOWN(Field(args, 2));
    int _uniformType = Int_val(Field(args, 3));
    SetShaderValue(_shader, _locIndex, _value, _uniformType);
    return Val_unit;
}
*/

/*
value raylib_SetShaderValueV(value args)
{
    Shader _shader = UNKNOWN(Field(args, 0));
    int _locIndex = Int_val(Field(args, 1));
    const void * _value = UNKNOWN(Field(args, 2));
    int _uniformType = Int_val(Field(args, 3));
    int _count = Int_val(Field(args, 4));
    SetShaderValueV(_shader, _locIndex, _value, _uniformType, _count);
    return Val_unit;
}
*/

/*
value raylib_SetShaderValueMatrix(value args)
{
    Shader _shader = UNKNOWN(Field(args, 0));
    int _locIndex = Int_val(Field(args, 1));
    Matrix _mat = UNKNOWN(Field(args, 2));
    SetShaderValueMatrix(_shader, _locIndex, _mat);
    return Val_unit;
}
*/

/*
value raylib_SetShaderValueTexture(value args)
{
    Shader _shader = UNKNOWN(Field(args, 0));
    int _locIndex = Int_val(Field(args, 1));
    Texture2D _texture = Texture_val(Field(args, 2));
    SetShaderValueTexture(_shader, _locIndex, _texture);
    return Val_unit;
}
*/

/*
value raylib_UnloadShader(value arg)
{
    Shader _shader = UNKNOWN(arg);
    UnloadShader(_shader);
    return Val_unit;
}
*/

/*
value raylib_GetScreenToWorldRay(value args)
{
    Vector2 _position = Vector2_val(Field(args, 0));
    Camera _camera = UNKNOWN(Field(args, 1));
    Ray result = GetScreenToWorldRay(_position, _camera);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetScreenToWorldRayEx(value args)
{
    Vector2 _position = Vector2_val(Field(args, 0));
    Camera _camera = UNKNOWN(Field(args, 1));
    int _width = Int_val(Field(args, 2));
    int _height = Int_val(Field(args, 3));
    Ray result = GetScreenToWorldRayEx(_position, _camera, _width, _height);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetWorldToScreen(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    Camera _camera = UNKNOWN(Field(args, 1));
    Vector2 result = GetWorldToScreen(_position, _camera);
    return Val_vector2(result);
}
*/

/*
value raylib_GetWorldToScreenEx(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    Camera _camera = UNKNOWN(Field(args, 1));
    int _width = Int_val(Field(args, 2));
    int _height = Int_val(Field(args, 3));
    Vector2 result = GetWorldToScreenEx(_position, _camera, _width, _height);
    return Val_vector2(result);
}
*/

/*
value raylib_GetWorldToScreen2D(value args)
{
    Vector2 _position = Vector2_val(Field(args, 0));
    Camera2D _camera = UNKNOWN(Field(args, 1));
    Vector2 result = GetWorldToScreen2D(_position, _camera);
    return Val_vector2(result);
}
*/

/*
value raylib_GetScreenToWorld2D(value args)
{
    Vector2 _position = Vector2_val(Field(args, 0));
    Camera2D _camera = UNKNOWN(Field(args, 1));
    Vector2 result = GetScreenToWorld2D(_position, _camera);
    return Val_vector2(result);
}
*/

/*
value raylib_GetCameraMatrix(value arg)
{
    Camera _camera = UNKNOWN(arg);
    Matrix result = GetCameraMatrix(_camera);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetCameraMatrix2D(value arg)
{
    Camera2D _camera = UNKNOWN(arg);
    Matrix result = GetCameraMatrix2D(_camera);
    return UNKNOWN(result);
}
*/

value raylib_SetTargetFPS(value arg)
{
    int _fps = Int_val(arg);
    SetTargetFPS(_fps);
    return Val_unit;
}

value raylib_GetFrameTime(value unit)
{
    float result = GetFrameTime();
    return copy_double(result);
}

/*
value raylib_GetTime(value unit)
{
    double result = GetTime();
    return UNKNOWN(result);
}
*/

value raylib_GetFPS(value unit)
{
    int result = GetFPS();
    return Val_int(result);
}

value raylib_SwapScreenBuffer(value unit)
{
    SwapScreenBuffer();
    return Val_unit;
}

value raylib_PollInputEvents(value unit)
{
    PollInputEvents();
    return Val_unit;
}

/*
value raylib_WaitTime(value arg)
{
    double _seconds = UNKNOWN(arg);
    WaitTime(_seconds);
    return Val_unit;
}
*/

value raylib_SetRandomSeed(value arg)
{
    unsigned int _seed = Long_val(arg);
    SetRandomSeed(_seed);
    return Val_unit;
}

value raylib_GetRandomValue(value args)
{
    int _min = Int_val(Field(args, 0));
    int _max = Int_val(Field(args, 1));
    int result = GetRandomValue(_min, _max);
    return Val_int(result);
}

/*
value raylib_LoadRandomSequence(value args)
{
    unsigned int _count = Long_val(Field(args, 0));
    int _min = Int_val(Field(args, 1));
    int _max = Int_val(Field(args, 2));
    int * result = LoadRandomSequence(_count, _min, _max);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadRandomSequence(value arg)
{
    int * _sequence = UNKNOWN(arg);
    UnloadRandomSequence(_sequence);
    return Val_unit;
}
*/

value raylib_TakeScreenshot(value arg)
{
    const char * _fileName = String_val(arg);
    TakeScreenshot(_fileName);
    return Val_unit;
}

value raylib_SetConfigFlags(value arg)
{
    unsigned int _flags = Long_val(arg);
    SetConfigFlags(_flags);
    return Val_unit;
}

value raylib_OpenURL(value arg)
{
    const char * _url = String_val(arg);
    OpenURL(_url);
    return Val_unit;
}

/*
value raylib_TraceLog(value args)
{
    int _logLevel = Int_val(Field(args, 0));
    const char * _text = String_val(Field(args, 1));
    ... _args = UNKNOWN(Field(args, 2));
    TraceLog(_logLevel, _text, _args);
    return Val_unit;
}
*/

value raylib_SetTraceLogLevel(value arg)
{
    int _logLevel = Int_val(arg);
    SetTraceLogLevel(_logLevel);
    return Val_unit;
}

/*
value raylib_MemAlloc(value arg)
{
    unsigned int _size = Long_val(arg);
    void * result = MemAlloc(_size);
    return UNKNOWN(result);
}
*/

/*
value raylib_MemRealloc(value args)
{
    void * _ptr = UNKNOWN(Field(args, 0));
    unsigned int _size = Long_val(Field(args, 1));
    void * result = MemRealloc(_ptr, _size);
    return UNKNOWN(result);
}
*/

/*
value raylib_MemFree(value arg)
{
    void * _ptr = UNKNOWN(arg);
    MemFree(_ptr);
    return Val_unit;
}
*/

/*
value raylib_SetTraceLogCallback(value arg)
{
    TraceLogCallback _callback = UNKNOWN(arg);
    SetTraceLogCallback(_callback);
    return Val_unit;
}
*/

/*
value raylib_SetLoadFileDataCallback(value arg)
{
    LoadFileDataCallback _callback = UNKNOWN(arg);
    SetLoadFileDataCallback(_callback);
    return Val_unit;
}
*/

/*
value raylib_SetSaveFileDataCallback(value arg)
{
    SaveFileDataCallback _callback = UNKNOWN(arg);
    SetSaveFileDataCallback(_callback);
    return Val_unit;
}
*/

/*
value raylib_SetLoadFileTextCallback(value arg)
{
    LoadFileTextCallback _callback = UNKNOWN(arg);
    SetLoadFileTextCallback(_callback);
    return Val_unit;
}
*/

/*
value raylib_SetSaveFileTextCallback(value arg)
{
    SaveFileTextCallback _callback = UNKNOWN(arg);
    SetSaveFileTextCallback(_callback);
    return Val_unit;
}
*/

/*
value raylib_LoadFileData(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    int * _dataSize = UNKNOWN(Field(args, 1));
    unsigned char * result = LoadFileData(_fileName, _dataSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadFileData(value arg)
{
    unsigned char * _data = UNKNOWN(arg);
    UnloadFileData(_data);
    return Val_unit;
}
*/

/*
value raylib_SaveFileData(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    void * _data = UNKNOWN(Field(args, 1));
    int _dataSize = Int_val(Field(args, 2));
    bool result = SaveFileData(_fileName, _data, _dataSize);
    return Val_bool(result);
}
*/

/*
value raylib_ExportDataAsCode(value args)
{
    const unsigned char * _data = UNKNOWN(Field(args, 0));
    int _dataSize = Int_val(Field(args, 1));
    const char * _fileName = String_val(Field(args, 2));
    bool result = ExportDataAsCode(_data, _dataSize, _fileName);
    return Val_bool(result);
}
*/

/*
value raylib_LoadFileText(value arg)
{
    const char * _fileName = String_val(arg);
    char * result = LoadFileText(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadFileText(value arg)
{
    char * _text = UNKNOWN(arg);
    UnloadFileText(_text);
    return Val_unit;
}
*/

/*
value raylib_SaveFileText(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    char * _text = UNKNOWN(Field(args, 1));
    bool result = SaveFileText(_fileName, _text);
    return Val_bool(result);
}
*/

value raylib_FileExists(value arg)
{
    const char * _fileName = String_val(arg);
    bool result = FileExists(_fileName);
    return Val_bool(result);
}

value raylib_DirectoryExists(value arg)
{
    const char * _dirPath = String_val(arg);
    bool result = DirectoryExists(_dirPath);
    return Val_bool(result);
}

value raylib_IsFileExtension(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    const char * _ext = String_val(Field(args, 1));
    bool result = IsFileExtension(_fileName, _ext);
    return Val_bool(result);
}

value raylib_GetFileLength(value arg)
{
    const char * _fileName = String_val(arg);
    int result = GetFileLength(_fileName);
    return Val_int(result);
}

value raylib_GetFileExtension(value arg)
{
    const char * _fileName = String_val(arg);
    const char * result = GetFileExtension(_fileName);
    return Val_string(result);
}

value raylib_GetFileName(value arg)
{
    const char * _filePath = String_val(arg);
    const char * result = GetFileName(_filePath);
    return Val_string(result);
}

value raylib_GetFileNameWithoutExt(value arg)
{
    const char * _filePath = String_val(arg);
    const char * result = GetFileNameWithoutExt(_filePath);
    return Val_string(result);
}

value raylib_GetDirectoryPath(value arg)
{
    const char * _filePath = String_val(arg);
    const char * result = GetDirectoryPath(_filePath);
    return Val_string(result);
}

value raylib_GetPrevDirectoryPath(value arg)
{
    const char * _dirPath = String_val(arg);
    const char * result = GetPrevDirectoryPath(_dirPath);
    return Val_string(result);
}

value raylib_GetWorkingDirectory(value unit)
{
    const char * result = GetWorkingDirectory();
    return Val_string(result);
}

value raylib_GetApplicationDirectory(value unit)
{
    const char * result = GetApplicationDirectory();
    return Val_string(result);
}

value raylib_MakeDirectory(value arg)
{
    const char * _dirPath = String_val(arg);
    int result = MakeDirectory(_dirPath);
    return Val_int(result);
}

value raylib_ChangeDirectory(value arg)
{
    const char * _dir = String_val(arg);
    bool result = ChangeDirectory(_dir);
    return Val_bool(result);
}

value raylib_IsPathFile(value arg)
{
    const char * _path = String_val(arg);
    bool result = IsPathFile(_path);
    return Val_bool(result);
}

value raylib_IsFileNameValid(value arg)
{
    const char * _fileName = String_val(arg);
    bool result = IsFileNameValid(_fileName);
    return Val_bool(result);
}

/*
value raylib_LoadDirectoryFiles(value arg)
{
    const char * _dirPath = String_val(arg);
    FilePathList result = LoadDirectoryFiles(_dirPath);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadDirectoryFilesEx(value args)
{
    const char * _basePath = String_val(Field(args, 0));
    const char * _filter = String_val(Field(args, 1));
    bool _scanSubdirs = Bool_val(Field(args, 2));
    FilePathList result = LoadDirectoryFilesEx(_basePath, _filter, _scanSubdirs);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadDirectoryFiles(value arg)
{
    FilePathList _files = UNKNOWN(arg);
    UnloadDirectoryFiles(_files);
    return Val_unit;
}
*/

value raylib_IsFileDropped(value unit)
{
    bool result = IsFileDropped();
    return Val_bool(result);
}

/*
value raylib_LoadDroppedFiles(value unit)
{
    FilePathList result = LoadDroppedFiles();
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadDroppedFiles(value arg)
{
    FilePathList _files = UNKNOWN(arg);
    UnloadDroppedFiles(_files);
    return Val_unit;
}
*/

/*
value raylib_GetFileModTime(value arg)
{
    const char * _fileName = String_val(arg);
    long result = GetFileModTime(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_CompressData(value args)
{
    const unsigned char * _data = UNKNOWN(Field(args, 0));
    int _dataSize = Int_val(Field(args, 1));
    int * _compDataSize = UNKNOWN(Field(args, 2));
    unsigned char * result = CompressData(_data, _dataSize, _compDataSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_DecompressData(value args)
{
    const unsigned char * _compData = UNKNOWN(Field(args, 0));
    int _compDataSize = Int_val(Field(args, 1));
    int * _dataSize = UNKNOWN(Field(args, 2));
    unsigned char * result = DecompressData(_compData, _compDataSize, _dataSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_EncodeDataBase64(value args)
{
    const unsigned char * _data = UNKNOWN(Field(args, 0));
    int _dataSize = Int_val(Field(args, 1));
    int * _outputSize = UNKNOWN(Field(args, 2));
    char * result = EncodeDataBase64(_data, _dataSize, _outputSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_DecodeDataBase64(value args)
{
    const unsigned char * _data = UNKNOWN(Field(args, 0));
    int * _outputSize = UNKNOWN(Field(args, 1));
    unsigned char * result = DecodeDataBase64(_data, _outputSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_ComputeCRC32(value args)
{
    unsigned char * _data = UNKNOWN(Field(args, 0));
    int _dataSize = Int_val(Field(args, 1));
    unsigned int result = ComputeCRC32(_data, _dataSize);
    return Val_long(result);
}
*/

/*
value raylib_ComputeMD5(value args)
{
    unsigned char * _data = UNKNOWN(Field(args, 0));
    int _dataSize = Int_val(Field(args, 1));
    unsigned int * result = ComputeMD5(_data, _dataSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_ComputeSHA1(value args)
{
    unsigned char * _data = UNKNOWN(Field(args, 0));
    int _dataSize = Int_val(Field(args, 1));
    unsigned int * result = ComputeSHA1(_data, _dataSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadAutomationEventList(value arg)
{
    const char * _fileName = String_val(arg);
    AutomationEventList result = LoadAutomationEventList(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadAutomationEventList(value arg)
{
    AutomationEventList _list = UNKNOWN(arg);
    UnloadAutomationEventList(_list);
    return Val_unit;
}
*/

/*
value raylib_ExportAutomationEventList(value args)
{
    AutomationEventList _list = UNKNOWN(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportAutomationEventList(_list, _fileName);
    return Val_bool(result);
}
*/

/*
value raylib_SetAutomationEventList(value arg)
{
    AutomationEventList * _list = UNKNOWN(arg);
    SetAutomationEventList(_list);
    return Val_unit;
}
*/

value raylib_SetAutomationEventBaseFrame(value arg)
{
    int _frame = Int_val(arg);
    SetAutomationEventBaseFrame(_frame);
    return Val_unit;
}

value raylib_StartAutomationEventRecording(value unit)
{
    StartAutomationEventRecording();
    return Val_unit;
}

value raylib_StopAutomationEventRecording(value unit)
{
    StopAutomationEventRecording();
    return Val_unit;
}

/*
value raylib_PlayAutomationEvent(value arg)
{
    AutomationEvent _event = UNKNOWN(arg);
    PlayAutomationEvent(_event);
    return Val_unit;
}
*/

value raylib_IsKeyPressed(value arg)
{
    int _key = Int_val(arg);
    bool result = IsKeyPressed(_key);
    return Val_bool(result);
}

value raylib_IsKeyPressedRepeat(value arg)
{
    int _key = Int_val(arg);
    bool result = IsKeyPressedRepeat(_key);
    return Val_bool(result);
}

value raylib_IsKeyDown(value arg)
{
    int _key = Int_val(arg);
    bool result = IsKeyDown(_key);
    return Val_bool(result);
}

value raylib_IsKeyReleased(value arg)
{
    int _key = Int_val(arg);
    bool result = IsKeyReleased(_key);
    return Val_bool(result);
}

value raylib_IsKeyUp(value arg)
{
    int _key = Int_val(arg);
    bool result = IsKeyUp(_key);
    return Val_bool(result);
}

value raylib_GetKeyPressed(value unit)
{
    int result = GetKeyPressed();
    return Val_int(result);
}

value raylib_GetCharPressed(value unit)
{
    int result = GetCharPressed();
    return Val_int(result);
}

value raylib_SetExitKey(value arg)
{
    int _key = Int_val(arg);
    SetExitKey(_key);
    return Val_unit;
}

value raylib_IsGamepadAvailable(value arg)
{
    int _gamepad = Int_val(arg);
    bool result = IsGamepadAvailable(_gamepad);
    return Val_bool(result);
}

value raylib_GetGamepadName(value arg)
{
    int _gamepad = Int_val(arg);
    const char * result = GetGamepadName(_gamepad);
    return Val_string(result);
}

value raylib_IsGamepadButtonPressed(value args)
{
    int _gamepad = Int_val(Field(args, 0));
    int _button = Int_val(Field(args, 1));
    bool result = IsGamepadButtonPressed(_gamepad, _button);
    return Val_bool(result);
}

value raylib_IsGamepadButtonDown(value args)
{
    int _gamepad = Int_val(Field(args, 0));
    int _button = Int_val(Field(args, 1));
    bool result = IsGamepadButtonDown(_gamepad, _button);
    return Val_bool(result);
}

value raylib_IsGamepadButtonReleased(value args)
{
    int _gamepad = Int_val(Field(args, 0));
    int _button = Int_val(Field(args, 1));
    bool result = IsGamepadButtonReleased(_gamepad, _button);
    return Val_bool(result);
}

value raylib_IsGamepadButtonUp(value args)
{
    int _gamepad = Int_val(Field(args, 0));
    int _button = Int_val(Field(args, 1));
    bool result = IsGamepadButtonUp(_gamepad, _button);
    return Val_bool(result);
}

value raylib_GetGamepadButtonPressed(value unit)
{
    int result = GetGamepadButtonPressed();
    return Val_int(result);
}

value raylib_GetGamepadAxisCount(value arg)
{
    int _gamepad = Int_val(arg);
    int result = GetGamepadAxisCount(_gamepad);
    return Val_int(result);
}

value raylib_GetGamepadAxisMovement(value args)
{
    int _gamepad = Int_val(Field(args, 0));
    int _axis = Int_val(Field(args, 1));
    float result = GetGamepadAxisMovement(_gamepad, _axis);
    return copy_double(result);
}

value raylib_SetGamepadMappings(value arg)
{
    const char * _mappings = String_val(arg);
    int result = SetGamepadMappings(_mappings);
    return Val_int(result);
}

value raylib_SetGamepadVibration(value args)
{
    int _gamepad = Int_val(Field(args, 0));
    float _leftMotor = Double_val(Field(args, 1));
    float _rightMotor = Double_val(Field(args, 2));
    float _duration = Double_val(Field(args, 3));
    SetGamepadVibration(_gamepad, _leftMotor, _rightMotor, _duration);
    return Val_unit;
}

value raylib_IsMouseButtonPressed(value arg)
{
    int _button = Int_val(arg);
    bool result = IsMouseButtonPressed(_button);
    return Val_bool(result);
}

value raylib_IsMouseButtonDown(value arg)
{
    int _button = Int_val(arg);
    bool result = IsMouseButtonDown(_button);
    return Val_bool(result);
}

value raylib_IsMouseButtonReleased(value arg)
{
    int _button = Int_val(arg);
    bool result = IsMouseButtonReleased(_button);
    return Val_bool(result);
}

value raylib_IsMouseButtonUp(value arg)
{
    int _button = Int_val(arg);
    bool result = IsMouseButtonUp(_button);
    return Val_bool(result);
}

value raylib_GetMouseX(value unit)
{
    int result = GetMouseX();
    return Val_int(result);
}

value raylib_GetMouseY(value unit)
{
    int result = GetMouseY();
    return Val_int(result);
}

value raylib_GetMousePosition(value unit)
{
    Vector2 result = GetMousePosition();
    return Val_vector2(result);
}

value raylib_GetMouseDelta(value unit)
{
    Vector2 result = GetMouseDelta();
    return Val_vector2(result);
}

value raylib_SetMousePosition(value args)
{
    int _x = Int_val(Field(args, 0));
    int _y = Int_val(Field(args, 1));
    SetMousePosition(_x, _y);
    return Val_unit;
}

value raylib_SetMouseOffset(value args)
{
    int _offsetX = Int_val(Field(args, 0));
    int _offsetY = Int_val(Field(args, 1));
    SetMouseOffset(_offsetX, _offsetY);
    return Val_unit;
}

value raylib_SetMouseScale(value args)
{
    float _scaleX = Double_val(Field(args, 0));
    float _scaleY = Double_val(Field(args, 1));
    SetMouseScale(_scaleX, _scaleY);
    return Val_unit;
}

value raylib_GetMouseWheelMove(value unit)
{
    float result = GetMouseWheelMove();
    return copy_double(result);
}

value raylib_GetMouseWheelMoveV(value unit)
{
    Vector2 result = GetMouseWheelMoveV();
    return Val_vector2(result);
}

value raylib_SetMouseCursor(value arg)
{
    int _cursor = Int_val(arg);
    SetMouseCursor(_cursor);
    return Val_unit;
}

value raylib_GetTouchX(value unit)
{
    int result = GetTouchX();
    return Val_int(result);
}

value raylib_GetTouchY(value unit)
{
    int result = GetTouchY();
    return Val_int(result);
}

value raylib_GetTouchPosition(value arg)
{
    int _index = Int_val(arg);
    Vector2 result = GetTouchPosition(_index);
    return Val_vector2(result);
}

value raylib_GetTouchPointId(value arg)
{
    int _index = Int_val(arg);
    int result = GetTouchPointId(_index);
    return Val_int(result);
}

value raylib_GetTouchPointCount(value unit)
{
    int result = GetTouchPointCount();
    return Val_int(result);
}

value raylib_SetGesturesEnabled(value arg)
{
    unsigned int _flags = Long_val(arg);
    SetGesturesEnabled(_flags);
    return Val_unit;
}

value raylib_IsGestureDetected(value arg)
{
    unsigned int _gesture = Long_val(arg);
    bool result = IsGestureDetected(_gesture);
    return Val_bool(result);
}

value raylib_GetGestureDetected(value unit)
{
    int result = GetGestureDetected();
    return Val_int(result);
}

value raylib_GetGestureHoldDuration(value unit)
{
    float result = GetGestureHoldDuration();
    return copy_double(result);
}

value raylib_GetGestureDragVector(value unit)
{
    Vector2 result = GetGestureDragVector();
    return Val_vector2(result);
}

value raylib_GetGestureDragAngle(value unit)
{
    float result = GetGestureDragAngle();
    return copy_double(result);
}

value raylib_GetGesturePinchVector(value unit)
{
    Vector2 result = GetGesturePinchVector();
    return Val_vector2(result);
}

value raylib_GetGesturePinchAngle(value unit)
{
    float result = GetGesturePinchAngle();
    return copy_double(result);
}

/*
value raylib_UpdateCamera(value args)
{
    Camera * _camera = UNKNOWN(Field(args, 0));
    int _mode = Int_val(Field(args, 1));
    UpdateCamera(_camera, _mode);
    return Val_unit;
}
*/

/*
value raylib_UpdateCameraPro(value args)
{
    Camera * _camera = UNKNOWN(Field(args, 0));
    Vector3 _movement = UNKNOWN(Field(args, 1));
    Vector3 _rotation = UNKNOWN(Field(args, 2));
    float _zoom = Double_val(Field(args, 3));
    UpdateCameraPro(_camera, _movement, _rotation, _zoom);
    return Val_unit;
}
*/

value raylib_SetShapesTexture(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    Rectangle _source = Rectangle_val(Field(args, 1));
    SetShapesTexture(_texture, _source);
    return Val_unit;
}

value raylib_GetShapesTexture(value unit)
{
    Texture2D result = GetShapesTexture();
    return Val_texture(result);
}

value raylib_GetShapesTextureRectangle(value unit)
{
    Rectangle result = GetShapesTextureRectangle();
    return Val_rectangle(result);
}

value raylib_DrawPixel(value args)
{
    int _posX = Int_val(Field(args, 0));
    int _posY = Int_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawPixel(_posX, _posY, _color);
    return Val_unit;
}

value raylib_DrawPixelV(value args)
{
    Vector2 _position = Vector2_val(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    DrawPixelV(_position, _color);
    return Val_unit;
}

value raylib_DrawLine(value args)
{
    int _startPosX = Int_val(Field(args, 0));
    int _startPosY = Int_val(Field(args, 1));
    int _endPosX = Int_val(Field(args, 2));
    int _endPosY = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawLine(_startPosX, _startPosY, _endPosX, _endPosY, _color);
    return Val_unit;
}

value raylib_DrawLineV(value args)
{
    Vector2 _startPos = Vector2_val(Field(args, 0));
    Vector2 _endPos = Vector2_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawLineV(_startPos, _endPos, _color);
    return Val_unit;
}

value raylib_DrawLineEx(value args)
{
    Vector2 _startPos = Vector2_val(Field(args, 0));
    Vector2 _endPos = Vector2_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawLineEx(_startPos, _endPos, _thick, _color);
    return Val_unit;
}

/*
value raylib_DrawLineStrip(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawLineStrip(_points, _pointCount, _color);
    return Val_unit;
}
*/

value raylib_DrawLineBezier(value args)
{
    Vector2 _startPos = Vector2_val(Field(args, 0));
    Vector2 _endPos = Vector2_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawLineBezier(_startPos, _endPos, _thick, _color);
    return Val_unit;
}

value raylib_DrawCircle(value args)
{
    int _centerX = Int_val(Field(args, 0));
    int _centerY = Int_val(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawCircle(_centerX, _centerY, _radius, _color);
    return Val_unit;
}

value raylib_DrawCircleSector(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    float _startAngle = Double_val(Field(args, 2));
    float _endAngle = Double_val(Field(args, 3));
    int _segments = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCircleSector(_center, _radius, _startAngle, _endAngle, _segments, _color);
    return Val_unit;
}

value raylib_DrawCircleSectorLines(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    float _startAngle = Double_val(Field(args, 2));
    float _endAngle = Double_val(Field(args, 3));
    int _segments = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCircleSectorLines(_center, _radius, _startAngle, _endAngle, _segments, _color);
    return Val_unit;
}

value raylib_DrawCircleGradient(value args)
{
    int _centerX = Int_val(Field(args, 0));
    int _centerY = Int_val(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    Color _inner = Colour_val(Field(args, 3));
    Color _outer = Colour_val(Field(args, 4));
    DrawCircleGradient(_centerX, _centerY, _radius, _inner, _outer);
    return Val_unit;
}

value raylib_DrawCircleV(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawCircleV(_center, _radius, _color);
    return Val_unit;
}

value raylib_DrawCircleLines(value args)
{
    int _centerX = Int_val(Field(args, 0));
    int _centerY = Int_val(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawCircleLines(_centerX, _centerY, _radius, _color);
    return Val_unit;
}

value raylib_DrawCircleLinesV(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawCircleLinesV(_center, _radius, _color);
    return Val_unit;
}

value raylib_DrawEllipse(value args)
{
    int _centerX = Int_val(Field(args, 0));
    int _centerY = Int_val(Field(args, 1));
    float _radiusH = Double_val(Field(args, 2));
    float _radiusV = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawEllipse(_centerX, _centerY, _radiusH, _radiusV, _color);
    return Val_unit;
}

value raylib_DrawEllipseLines(value args)
{
    int _centerX = Int_val(Field(args, 0));
    int _centerY = Int_val(Field(args, 1));
    float _radiusH = Double_val(Field(args, 2));
    float _radiusV = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawEllipseLines(_centerX, _centerY, _radiusH, _radiusV, _color);
    return Val_unit;
}

value raylib_DrawRing(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _innerRadius = Double_val(Field(args, 1));
    float _outerRadius = Double_val(Field(args, 2));
    float _startAngle = Double_val(Field(args, 3));
    float _endAngle = Double_val(Field(args, 4));
    int _segments = Int_val(Field(args, 5));
    Color _color = Colour_val(Field(args, 6));
    DrawRing(_center, _innerRadius, _outerRadius, _startAngle, _endAngle, _segments, _color);
    return Val_unit;
}

value raylib_DrawRingLines(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _innerRadius = Double_val(Field(args, 1));
    float _outerRadius = Double_val(Field(args, 2));
    float _startAngle = Double_val(Field(args, 3));
    float _endAngle = Double_val(Field(args, 4));
    int _segments = Int_val(Field(args, 5));
    Color _color = Colour_val(Field(args, 6));
    DrawRingLines(_center, _innerRadius, _outerRadius, _startAngle, _endAngle, _segments, _color);
    return Val_unit;
}

value raylib_DrawRectangle(value args)
{
    int _posX = Int_val(Field(args, 0));
    int _posY = Int_val(Field(args, 1));
    int _width = Int_val(Field(args, 2));
    int _height = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawRectangle(_posX, _posY, _width, _height, _color);
    return Val_unit;
}

value raylib_DrawRectangleV(value args)
{
    Vector2 _position = Vector2_val(Field(args, 0));
    Vector2 _size = Vector2_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawRectangleV(_position, _size, _color);
    return Val_unit;
}

value raylib_DrawRectangleRec(value args)
{
    Rectangle _rec = Rectangle_val(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    DrawRectangleRec(_rec, _color);
    return Val_unit;
}

value raylib_DrawRectanglePro(value args)
{
    Rectangle _rec = Rectangle_val(Field(args, 0));
    Vector2 _origin = Vector2_val(Field(args, 1));
    float _rotation = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawRectanglePro(_rec, _origin, _rotation, _color);
    return Val_unit;
}

value raylib_DrawRectangleGradientV(value args)
{
    int _posX = Int_val(Field(args, 0));
    int _posY = Int_val(Field(args, 1));
    int _width = Int_val(Field(args, 2));
    int _height = Int_val(Field(args, 3));
    Color _top = Colour_val(Field(args, 4));
    Color _bottom = Colour_val(Field(args, 5));
    DrawRectangleGradientV(_posX, _posY, _width, _height, _top, _bottom);
    return Val_unit;
}

value raylib_DrawRectangleGradientH(value args)
{
    int _posX = Int_val(Field(args, 0));
    int _posY = Int_val(Field(args, 1));
    int _width = Int_val(Field(args, 2));
    int _height = Int_val(Field(args, 3));
    Color _left = Colour_val(Field(args, 4));
    Color _right = Colour_val(Field(args, 5));
    DrawRectangleGradientH(_posX, _posY, _width, _height, _left, _right);
    return Val_unit;
}

value raylib_DrawRectangleGradientEx(value args)
{
    Rectangle _rec = Rectangle_val(Field(args, 0));
    Color _topLeft = Colour_val(Field(args, 1));
    Color _bottomLeft = Colour_val(Field(args, 2));
    Color _topRight = Colour_val(Field(args, 3));
    Color _bottomRight = Colour_val(Field(args, 4));
    DrawRectangleGradientEx(_rec, _topLeft, _bottomLeft, _topRight, _bottomRight);
    return Val_unit;
}

value raylib_DrawRectangleLines(value args)
{
    int _posX = Int_val(Field(args, 0));
    int _posY = Int_val(Field(args, 1));
    int _width = Int_val(Field(args, 2));
    int _height = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawRectangleLines(_posX, _posY, _width, _height, _color);
    return Val_unit;
}

value raylib_DrawRectangleLinesEx(value args)
{
    Rectangle _rec = Rectangle_val(Field(args, 0));
    float _lineThick = Double_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawRectangleLinesEx(_rec, _lineThick, _color);
    return Val_unit;
}

value raylib_DrawRectangleRounded(value args)
{
    Rectangle _rec = Rectangle_val(Field(args, 0));
    float _roundness = Double_val(Field(args, 1));
    int _segments = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawRectangleRounded(_rec, _roundness, _segments, _color);
    return Val_unit;
}

value raylib_DrawRectangleRoundedLines(value args)
{
    Rectangle _rec = Rectangle_val(Field(args, 0));
    float _roundness = Double_val(Field(args, 1));
    int _segments = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawRectangleRoundedLines(_rec, _roundness, _segments, _color);
    return Val_unit;
}

value raylib_DrawRectangleRoundedLinesEx(value args)
{
    Rectangle _rec = Rectangle_val(Field(args, 0));
    float _roundness = Double_val(Field(args, 1));
    int _segments = Int_val(Field(args, 2));
    float _lineThick = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawRectangleRoundedLinesEx(_rec, _roundness, _segments, _lineThick, _color);
    return Val_unit;
}

value raylib_DrawTriangle(value args)
{
    Vector2 _v1 = Vector2_val(Field(args, 0));
    Vector2 _v2 = Vector2_val(Field(args, 1));
    Vector2 _v3 = Vector2_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawTriangle(_v1, _v2, _v3, _color);
    return Val_unit;
}

value raylib_DrawTriangleLines(value args)
{
    Vector2 _v1 = Vector2_val(Field(args, 0));
    Vector2 _v2 = Vector2_val(Field(args, 1));
    Vector2 _v3 = Vector2_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawTriangleLines(_v1, _v2, _v3, _color);
    return Val_unit;
}

/*
value raylib_DrawTriangleFan(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawTriangleFan(_points, _pointCount, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawTriangleStrip(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawTriangleStrip(_points, _pointCount, _color);
    return Val_unit;
}
*/

value raylib_DrawPoly(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    int _sides = Int_val(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    float _rotation = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawPoly(_center, _sides, _radius, _rotation, _color);
    return Val_unit;
}

value raylib_DrawPolyLines(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    int _sides = Int_val(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    float _rotation = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawPolyLines(_center, _sides, _radius, _rotation, _color);
    return Val_unit;
}

value raylib_DrawPolyLinesEx(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    int _sides = Int_val(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    float _rotation = Double_val(Field(args, 3));
    float _lineThick = Double_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawPolyLinesEx(_center, _sides, _radius, _rotation, _lineThick, _color);
    return Val_unit;
}

/*
value raylib_DrawSplineLinear(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawSplineLinear(_points, _pointCount, _thick, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawSplineBasis(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawSplineBasis(_points, _pointCount, _thick, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawSplineCatmullRom(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawSplineCatmullRom(_points, _pointCount, _thick, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawSplineBezierQuadratic(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawSplineBezierQuadratic(_points, _pointCount, _thick, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawSplineBezierCubic(value args)
{
    const Vector2 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawSplineBezierCubic(_points, _pointCount, _thick, _color);
    return Val_unit;
}
*/

value raylib_DrawSplineSegmentLinear(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _p2 = Vector2_val(Field(args, 1));
    float _thick = Double_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawSplineSegmentLinear(_p1, _p2, _thick, _color);
    return Val_unit;
}

value raylib_DrawSplineSegmentBasis(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _p2 = Vector2_val(Field(args, 1));
    Vector2 _p3 = Vector2_val(Field(args, 2));
    Vector2 _p4 = Vector2_val(Field(args, 3));
    float _thick = Double_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawSplineSegmentBasis(_p1, _p2, _p3, _p4, _thick, _color);
    return Val_unit;
}

value raylib_DrawSplineSegmentCatmullRom(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _p2 = Vector2_val(Field(args, 1));
    Vector2 _p3 = Vector2_val(Field(args, 2));
    Vector2 _p4 = Vector2_val(Field(args, 3));
    float _thick = Double_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawSplineSegmentCatmullRom(_p1, _p2, _p3, _p4, _thick, _color);
    return Val_unit;
}

value raylib_DrawSplineSegmentBezierQuadratic(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _c2 = Vector2_val(Field(args, 1));
    Vector2 _p3 = Vector2_val(Field(args, 2));
    float _thick = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawSplineSegmentBezierQuadratic(_p1, _c2, _p3, _thick, _color);
    return Val_unit;
}

value raylib_DrawSplineSegmentBezierCubic(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _c2 = Vector2_val(Field(args, 1));
    Vector2 _c3 = Vector2_val(Field(args, 2));
    Vector2 _p4 = Vector2_val(Field(args, 3));
    float _thick = Double_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawSplineSegmentBezierCubic(_p1, _c2, _c3, _p4, _thick, _color);
    return Val_unit;
}

value raylib_GetSplinePointLinear(value args)
{
    Vector2 _startPos = Vector2_val(Field(args, 0));
    Vector2 _endPos = Vector2_val(Field(args, 1));
    float _t = Double_val(Field(args, 2));
    Vector2 result = GetSplinePointLinear(_startPos, _endPos, _t);
    return Val_vector2(result);
}

value raylib_GetSplinePointBasis(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _p2 = Vector2_val(Field(args, 1));
    Vector2 _p3 = Vector2_val(Field(args, 2));
    Vector2 _p4 = Vector2_val(Field(args, 3));
    float _t = Double_val(Field(args, 4));
    Vector2 result = GetSplinePointBasis(_p1, _p2, _p3, _p4, _t);
    return Val_vector2(result);
}

value raylib_GetSplinePointCatmullRom(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _p2 = Vector2_val(Field(args, 1));
    Vector2 _p3 = Vector2_val(Field(args, 2));
    Vector2 _p4 = Vector2_val(Field(args, 3));
    float _t = Double_val(Field(args, 4));
    Vector2 result = GetSplinePointCatmullRom(_p1, _p2, _p3, _p4, _t);
    return Val_vector2(result);
}

value raylib_GetSplinePointBezierQuad(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _c2 = Vector2_val(Field(args, 1));
    Vector2 _p3 = Vector2_val(Field(args, 2));
    float _t = Double_val(Field(args, 3));
    Vector2 result = GetSplinePointBezierQuad(_p1, _c2, _p3, _t);
    return Val_vector2(result);
}

value raylib_GetSplinePointBezierCubic(value args)
{
    Vector2 _p1 = Vector2_val(Field(args, 0));
    Vector2 _c2 = Vector2_val(Field(args, 1));
    Vector2 _c3 = Vector2_val(Field(args, 2));
    Vector2 _p4 = Vector2_val(Field(args, 3));
    float _t = Double_val(Field(args, 4));
    Vector2 result = GetSplinePointBezierCubic(_p1, _c2, _c3, _p4, _t);
    return Val_vector2(result);
}

value raylib_CheckCollisionRecs(value args)
{
    Rectangle _rec1 = Rectangle_val(Field(args, 0));
    Rectangle _rec2 = Rectangle_val(Field(args, 1));
    bool result = CheckCollisionRecs(_rec1, _rec2);
    return Val_bool(result);
}

value raylib_CheckCollisionCircles(value args)
{
    Vector2 _center1 = Vector2_val(Field(args, 0));
    float _radius1 = Double_val(Field(args, 1));
    Vector2 _center2 = Vector2_val(Field(args, 2));
    float _radius2 = Double_val(Field(args, 3));
    bool result = CheckCollisionCircles(_center1, _radius1, _center2, _radius2);
    return Val_bool(result);
}

value raylib_CheckCollisionCircleRec(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    Rectangle _rec = Rectangle_val(Field(args, 2));
    bool result = CheckCollisionCircleRec(_center, _radius, _rec);
    return Val_bool(result);
}

value raylib_CheckCollisionCircleLine(value args)
{
    Vector2 _center = Vector2_val(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    Vector2 _p1 = Vector2_val(Field(args, 2));
    Vector2 _p2 = Vector2_val(Field(args, 3));
    bool result = CheckCollisionCircleLine(_center, _radius, _p1, _p2);
    return Val_bool(result);
}

value raylib_CheckCollisionPointRec(value args)
{
    Vector2 _point = Vector2_val(Field(args, 0));
    Rectangle _rec = Rectangle_val(Field(args, 1));
    bool result = CheckCollisionPointRec(_point, _rec);
    return Val_bool(result);
}

value raylib_CheckCollisionPointCircle(value args)
{
    Vector2 _point = Vector2_val(Field(args, 0));
    Vector2 _center = Vector2_val(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    bool result = CheckCollisionPointCircle(_point, _center, _radius);
    return Val_bool(result);
}

value raylib_CheckCollisionPointTriangle(value args)
{
    Vector2 _point = Vector2_val(Field(args, 0));
    Vector2 _p1 = Vector2_val(Field(args, 1));
    Vector2 _p2 = Vector2_val(Field(args, 2));
    Vector2 _p3 = Vector2_val(Field(args, 3));
    bool result = CheckCollisionPointTriangle(_point, _p1, _p2, _p3);
    return Val_bool(result);
}

value raylib_CheckCollisionPointLine(value args)
{
    Vector2 _point = Vector2_val(Field(args, 0));
    Vector2 _p1 = Vector2_val(Field(args, 1));
    Vector2 _p2 = Vector2_val(Field(args, 2));
    int _threshold = Int_val(Field(args, 3));
    bool result = CheckCollisionPointLine(_point, _p1, _p2, _threshold);
    return Val_bool(result);
}

/*
value raylib_CheckCollisionPointPoly(value args)
{
    Vector2 _point = Vector2_val(Field(args, 0));
    const Vector2 * _points = UNKNOWN(Field(args, 1));
    int _pointCount = Int_val(Field(args, 2));
    bool result = CheckCollisionPointPoly(_point, _points, _pointCount);
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionLines(value args)
{
    Vector2 _startPos1 = Vector2_val(Field(args, 0));
    Vector2 _endPos1 = Vector2_val(Field(args, 1));
    Vector2 _startPos2 = Vector2_val(Field(args, 2));
    Vector2 _endPos2 = Vector2_val(Field(args, 3));
    Vector2 * _collisionPoint = UNKNOWN(Field(args, 4));
    bool result = CheckCollisionLines(_startPos1, _endPos1, _startPos2, _endPos2, _collisionPoint);
    return Val_bool(result);
}
*/

value raylib_GetCollisionRec(value args)
{
    Rectangle _rec1 = Rectangle_val(Field(args, 0));
    Rectangle _rec2 = Rectangle_val(Field(args, 1));
    Rectangle result = GetCollisionRec(_rec1, _rec2);
    return Val_rectangle(result);
}

value raylib_LoadImage(value arg)
{
    const char * _fileName = String_val(arg);
    Image result = LoadImage(_fileName);
    return Val_image(result);
}

value raylib_LoadImageRaw(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    int _width = Int_val(Field(args, 1));
    int _height = Int_val(Field(args, 2));
    int _format = Int_val(Field(args, 3));
    int _headerSize = Int_val(Field(args, 4));
    Image result = LoadImageRaw(_fileName, _width, _height, _format, _headerSize);
    return Val_image(result);
}

/*
value raylib_LoadImageAnim(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    int * _frames = UNKNOWN(Field(args, 1));
    Image result = LoadImageAnim(_fileName, _frames);
    return Val_image(result);
}
*/

/*
value raylib_LoadImageAnimFromMemory(value args)
{
    const char * _fileType = String_val(Field(args, 0));
    const unsigned char * _fileData = UNKNOWN(Field(args, 1));
    int _dataSize = Int_val(Field(args, 2));
    int * _frames = UNKNOWN(Field(args, 3));
    Image result = LoadImageAnimFromMemory(_fileType, _fileData, _dataSize, _frames);
    return Val_image(result);
}
*/

/*
value raylib_LoadImageFromMemory(value args)
{
    const char * _fileType = String_val(Field(args, 0));
    const unsigned char * _fileData = UNKNOWN(Field(args, 1));
    int _dataSize = Int_val(Field(args, 2));
    Image result = LoadImageFromMemory(_fileType, _fileData, _dataSize);
    return Val_image(result);
}
*/

value raylib_LoadImageFromTexture(value arg)
{
    Texture2D _texture = Texture_val(arg);
    Image result = LoadImageFromTexture(_texture);
    return Val_image(result);
}

value raylib_LoadImageFromScreen(value unit)
{
    Image result = LoadImageFromScreen();
    return Val_image(result);
}

value raylib_IsImageValid(value arg)
{
    Image _image = Image_val(arg);
    bool result = IsImageValid(_image);
    return Val_bool(result);
}

value raylib_UnloadImage(value arg)
{
    Image _image = Image_val(arg);
    UnloadImage(_image);
    return Val_unit;
}

value raylib_ExportImage(value args)
{
    Image _image = Image_val(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportImage(_image, _fileName);
    return Val_bool(result);
}

/*
value raylib_ExportImageToMemory(value args)
{
    Image _image = Image_val(Field(args, 0));
    const char * _fileType = String_val(Field(args, 1));
    int * _fileSize = UNKNOWN(Field(args, 2));
    unsigned char * result = ExportImageToMemory(_image, _fileType, _fileSize);
    return UNKNOWN(result);
}
*/

value raylib_ExportImageAsCode(value args)
{
    Image _image = Image_val(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportImageAsCode(_image, _fileName);
    return Val_bool(result);
}

value raylib_GenImageColor(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    Image result = GenImageColor(_width, _height, _color);
    return Val_image(result);
}

value raylib_GenImageGradientLinear(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    int _direction = Int_val(Field(args, 2));
    Color _start = Colour_val(Field(args, 3));
    Color _end = Colour_val(Field(args, 4));
    Image result = GenImageGradientLinear(_width, _height, _direction, _start, _end);
    return Val_image(result);
}

value raylib_GenImageGradientRadial(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    float _density = Double_val(Field(args, 2));
    Color _inner = Colour_val(Field(args, 3));
    Color _outer = Colour_val(Field(args, 4));
    Image result = GenImageGradientRadial(_width, _height, _density, _inner, _outer);
    return Val_image(result);
}

value raylib_GenImageGradientSquare(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    float _density = Double_val(Field(args, 2));
    Color _inner = Colour_val(Field(args, 3));
    Color _outer = Colour_val(Field(args, 4));
    Image result = GenImageGradientSquare(_width, _height, _density, _inner, _outer);
    return Val_image(result);
}

value raylib_GenImageChecked(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    int _checksX = Int_val(Field(args, 2));
    int _checksY = Int_val(Field(args, 3));
    Color _col1 = Colour_val(Field(args, 4));
    Color _col2 = Colour_val(Field(args, 5));
    Image result = GenImageChecked(_width, _height, _checksX, _checksY, _col1, _col2);
    return Val_image(result);
}

value raylib_GenImageWhiteNoise(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    float _factor = Double_val(Field(args, 2));
    Image result = GenImageWhiteNoise(_width, _height, _factor);
    return Val_image(result);
}

value raylib_GenImagePerlinNoise(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    int _offsetX = Int_val(Field(args, 2));
    int _offsetY = Int_val(Field(args, 3));
    float _scale = Double_val(Field(args, 4));
    Image result = GenImagePerlinNoise(_width, _height, _offsetX, _offsetY, _scale);
    return Val_image(result);
}

value raylib_GenImageCellular(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    int _tileSize = Int_val(Field(args, 2));
    Image result = GenImageCellular(_width, _height, _tileSize);
    return Val_image(result);
}

value raylib_GenImageText(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    const char * _text = String_val(Field(args, 2));
    Image result = GenImageText(_width, _height, _text);
    return Val_image(result);
}

value raylib_ImageCopy(value arg)
{
    Image _image = Image_val(arg);
    Image result = ImageCopy(_image);
    return Val_image(result);
}

value raylib_ImageFromImage(value args)
{
    Image _image = Image_val(Field(args, 0));
    Rectangle _rec = Rectangle_val(Field(args, 1));
    Image result = ImageFromImage(_image, _rec);
    return Val_image(result);
}

value raylib_ImageFromChannel(value args)
{
    Image _image = Image_val(Field(args, 0));
    int _selectedChannel = Int_val(Field(args, 1));
    Image result = ImageFromChannel(_image, _selectedChannel);
    return Val_image(result);
}

value raylib_ImageText(value args)
{
    const char * _text = String_val(Field(args, 0));
    int _fontSize = Int_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    Image result = ImageText(_text, _fontSize, _color);
    return Val_image(result);
}

/*
value raylib_ImageTextEx(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    const char * _text = String_val(Field(args, 1));
    float _fontSize = Double_val(Field(args, 2));
    float _spacing = Double_val(Field(args, 3));
    Color _tint = Colour_val(Field(args, 4));
    Image result = ImageTextEx(_font, _text, _fontSize, _spacing, _tint);
    return Val_image(result);
}
*/

/*
value raylib_ImageFormat(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _newFormat = Int_val(Field(args, 1));
    ImageFormat(_image, _newFormat);
    return Val_unit;
}
*/

/*
value raylib_ImageToPOT(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    Color _fill = Colour_val(Field(args, 1));
    ImageToPOT(_image, _fill);
    return Val_unit;
}
*/

/*
value raylib_ImageCrop(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    Rectangle _crop = Rectangle_val(Field(args, 1));
    ImageCrop(_image, _crop);
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaCrop(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    float _threshold = Double_val(Field(args, 1));
    ImageAlphaCrop(_image, _threshold);
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaClear(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    float _threshold = Double_val(Field(args, 2));
    ImageAlphaClear(_image, _color, _threshold);
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaMask(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    Image _alphaMask = Image_val(Field(args, 1));
    ImageAlphaMask(_image, _alphaMask);
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaPremultiply(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageAlphaPremultiply(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageBlurGaussian(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _blurSize = Int_val(Field(args, 1));
    ImageBlurGaussian(_image, _blurSize);
    return Val_unit;
}
*/

/*
value raylib_ImageKernelConvolution(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    const float * _kernel = UNKNOWN(Field(args, 1));
    int _kernelSize = Int_val(Field(args, 2));
    ImageKernelConvolution(_image, _kernel, _kernelSize);
    return Val_unit;
}
*/

/*
value raylib_ImageResize(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _newWidth = Int_val(Field(args, 1));
    int _newHeight = Int_val(Field(args, 2));
    ImageResize(_image, _newWidth, _newHeight);
    return Val_unit;
}
*/

/*
value raylib_ImageResizeNN(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _newWidth = Int_val(Field(args, 1));
    int _newHeight = Int_val(Field(args, 2));
    ImageResizeNN(_image, _newWidth, _newHeight);
    return Val_unit;
}
*/

/*
value raylib_ImageResizeCanvas(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _newWidth = Int_val(Field(args, 1));
    int _newHeight = Int_val(Field(args, 2));
    int _offsetX = Int_val(Field(args, 3));
    int _offsetY = Int_val(Field(args, 4));
    Color _fill = Colour_val(Field(args, 5));
    ImageResizeCanvas(_image, _newWidth, _newHeight, _offsetX, _offsetY, _fill);
    return Val_unit;
}
*/

/*
value raylib_ImageMipmaps(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageMipmaps(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageDither(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _rBpp = Int_val(Field(args, 1));
    int _gBpp = Int_val(Field(args, 2));
    int _bBpp = Int_val(Field(args, 3));
    int _aBpp = Int_val(Field(args, 4));
    ImageDither(_image, _rBpp, _gBpp, _bBpp, _aBpp);
    return Val_unit;
}
*/

/*
value raylib_ImageFlipVertical(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageFlipVertical(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageFlipHorizontal(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageFlipHorizontal(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageRotate(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _degrees = Int_val(Field(args, 1));
    ImageRotate(_image, _degrees);
    return Val_unit;
}
*/

/*
value raylib_ImageRotateCW(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageRotateCW(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageRotateCCW(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageRotateCCW(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageColorTint(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    ImageColorTint(_image, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageColorInvert(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageColorInvert(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageColorGrayscale(value arg)
{
    Image * _image = UNKNOWN(arg);
    ImageColorGrayscale(_image);
    return Val_unit;
}
*/

/*
value raylib_ImageColorContrast(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    float _contrast = Double_val(Field(args, 1));
    ImageColorContrast(_image, _contrast);
    return Val_unit;
}
*/

/*
value raylib_ImageColorBrightness(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    int _brightness = Int_val(Field(args, 1));
    ImageColorBrightness(_image, _brightness);
    return Val_unit;
}
*/

/*
value raylib_ImageColorReplace(value args)
{
    Image * _image = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    Color _replace = Colour_val(Field(args, 2));
    ImageColorReplace(_image, _color, _replace);
    return Val_unit;
}
*/

/*
value raylib_LoadImageColors(value arg)
{
    Image _image = Image_val(arg);
    Color * result = LoadImageColors(_image);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImagePalette(value args)
{
    Image _image = Image_val(Field(args, 0));
    int _maxPaletteSize = Int_val(Field(args, 1));
    int * _colorCount = UNKNOWN(Field(args, 2));
    Color * result = LoadImagePalette(_image, _maxPaletteSize, _colorCount);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadImageColors(value arg)
{
    Color * _colors = UNKNOWN(arg);
    UnloadImageColors(_colors);
    return Val_unit;
}
*/

/*
value raylib_UnloadImagePalette(value arg)
{
    Color * _colors = UNKNOWN(arg);
    UnloadImagePalette(_colors);
    return Val_unit;
}
*/

value raylib_GetImageAlphaBorder(value args)
{
    Image _image = Image_val(Field(args, 0));
    float _threshold = Double_val(Field(args, 1));
    Rectangle result = GetImageAlphaBorder(_image, _threshold);
    return Val_rectangle(result);
}

value raylib_GetImageColor(value args)
{
    Image _image = Image_val(Field(args, 0));
    int _x = Int_val(Field(args, 1));
    int _y = Int_val(Field(args, 2));
    Color result = GetImageColor(_image, _x, _y);
    return Val_colour(result);
}

/*
value raylib_ImageClearBackground(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    ImageClearBackground(_dst, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawPixel(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    int _posX = Int_val(Field(args, 1));
    int _posY = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawPixel(_dst, _posX, _posY, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawPixelV(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _position = Vector2_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    ImageDrawPixelV(_dst, _position, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawLine(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    int _startPosX = Int_val(Field(args, 1));
    int _startPosY = Int_val(Field(args, 2));
    int _endPosX = Int_val(Field(args, 3));
    int _endPosY = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    ImageDrawLine(_dst, _startPosX, _startPosY, _endPosX, _endPosY, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawLineV(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _start = Vector2_val(Field(args, 1));
    Vector2 _end = Vector2_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawLineV(_dst, _start, _end, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawLineEx(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _start = Vector2_val(Field(args, 1));
    Vector2 _end = Vector2_val(Field(args, 2));
    int _thick = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    ImageDrawLineEx(_dst, _start, _end, _thick, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircle(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    int _centerX = Int_val(Field(args, 1));
    int _centerY = Int_val(Field(args, 2));
    int _radius = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    ImageDrawCircle(_dst, _centerX, _centerY, _radius, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircleV(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _center = Vector2_val(Field(args, 1));
    int _radius = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawCircleV(_dst, _center, _radius, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircleLines(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    int _centerX = Int_val(Field(args, 1));
    int _centerY = Int_val(Field(args, 2));
    int _radius = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    ImageDrawCircleLines(_dst, _centerX, _centerY, _radius, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircleLinesV(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _center = Vector2_val(Field(args, 1));
    int _radius = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawCircleLinesV(_dst, _center, _radius, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangle(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    int _posX = Int_val(Field(args, 1));
    int _posY = Int_val(Field(args, 2));
    int _width = Int_val(Field(args, 3));
    int _height = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    ImageDrawRectangle(_dst, _posX, _posY, _width, _height, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangleV(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _position = Vector2_val(Field(args, 1));
    Vector2 _size = Vector2_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawRectangleV(_dst, _position, _size, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangleRec(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Rectangle _rec = Rectangle_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    ImageDrawRectangleRec(_dst, _rec, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangleLines(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Rectangle _rec = Rectangle_val(Field(args, 1));
    int _thick = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawRectangleLines(_dst, _rec, _thick, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangle(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _v1 = Vector2_val(Field(args, 1));
    Vector2 _v2 = Vector2_val(Field(args, 2));
    Vector2 _v3 = Vector2_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    ImageDrawTriangle(_dst, _v1, _v2, _v3, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleEx(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _v1 = Vector2_val(Field(args, 1));
    Vector2 _v2 = Vector2_val(Field(args, 2));
    Vector2 _v3 = Vector2_val(Field(args, 3));
    Color _c1 = Colour_val(Field(args, 4));
    Color _c2 = Colour_val(Field(args, 5));
    Color _c3 = Colour_val(Field(args, 6));
    ImageDrawTriangleEx(_dst, _v1, _v2, _v3, _c1, _c2, _c3);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleLines(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 _v1 = Vector2_val(Field(args, 1));
    Vector2 _v2 = Vector2_val(Field(args, 2));
    Vector2 _v3 = Vector2_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    ImageDrawTriangleLines(_dst, _v1, _v2, _v3, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleFan(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 * _points = UNKNOWN(Field(args, 1));
    int _pointCount = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawTriangleFan(_dst, _points, _pointCount, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleStrip(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Vector2 * _points = UNKNOWN(Field(args, 1));
    int _pointCount = Int_val(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    ImageDrawTriangleStrip(_dst, _points, _pointCount, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDraw(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Image _src = Image_val(Field(args, 1));
    Rectangle _srcRec = Rectangle_val(Field(args, 2));
    Rectangle _dstRec = Rectangle_val(Field(args, 3));
    Color _tint = Colour_val(Field(args, 4));
    ImageDraw(_dst, _src, _srcRec, _dstRec, _tint);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawText(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    const char * _text = String_val(Field(args, 1));
    int _posX = Int_val(Field(args, 2));
    int _posY = Int_val(Field(args, 3));
    int _fontSize = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    ImageDrawText(_dst, _text, _posX, _posY, _fontSize, _color);
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTextEx(value args)
{
    Image * _dst = UNKNOWN(Field(args, 0));
    Font _font = UNKNOWN(Field(args, 1));
    const char * _text = String_val(Field(args, 2));
    Vector2 _position = Vector2_val(Field(args, 3));
    float _fontSize = Double_val(Field(args, 4));
    float _spacing = Double_val(Field(args, 5));
    Color _tint = Colour_val(Field(args, 6));
    ImageDrawTextEx(_dst, _font, _text, _position, _fontSize, _spacing, _tint);
    return Val_unit;
}
*/

value raylib_LoadTexture(value arg)
{
    const char * _fileName = String_val(arg);
    Texture2D result = LoadTexture(_fileName);
    return Val_texture(result);
}

value raylib_LoadTextureFromImage(value arg)
{
    Image _image = Image_val(arg);
    Texture2D result = LoadTextureFromImage(_image);
    return Val_texture(result);
}

/*
value raylib_LoadTextureCubemap(value args)
{
    Image _image = Image_val(Field(args, 0));
    int _layout = Int_val(Field(args, 1));
    TextureCubemap result = LoadTextureCubemap(_image, _layout);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadRenderTexture(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    RenderTexture2D result = LoadRenderTexture(_width, _height);
    return UNKNOWN(result);
}
*/

value raylib_IsTextureValid(value arg)
{
    Texture2D _texture = Texture_val(arg);
    bool result = IsTextureValid(_texture);
    return Val_bool(result);
}

value raylib_UnloadTexture(value arg)
{
    Texture2D _texture = Texture_val(arg);
    UnloadTexture(_texture);
    return Val_unit;
}

/*
value raylib_IsRenderTextureValid(value arg)
{
    RenderTexture2D _target = UNKNOWN(arg);
    bool result = IsRenderTextureValid(_target);
    return Val_bool(result);
}
*/

/*
value raylib_UnloadRenderTexture(value arg)
{
    RenderTexture2D _target = UNKNOWN(arg);
    UnloadRenderTexture(_target);
    return Val_unit;
}
*/

/*
value raylib_UpdateTexture(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    const void * _pixels = UNKNOWN(Field(args, 1));
    UpdateTexture(_texture, _pixels);
    return Val_unit;
}
*/

/*
value raylib_UpdateTextureRec(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    Rectangle _rec = Rectangle_val(Field(args, 1));
    const void * _pixels = UNKNOWN(Field(args, 2));
    UpdateTextureRec(_texture, _rec, _pixels);
    return Val_unit;
}
*/

/*
value raylib_GenTextureMipmaps(value arg)
{
    Texture2D * _texture = UNKNOWN(arg);
    GenTextureMipmaps(_texture);
    return Val_unit;
}
*/

value raylib_SetTextureFilter(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    int _filter = Int_val(Field(args, 1));
    SetTextureFilter(_texture, _filter);
    return Val_unit;
}

value raylib_SetTextureWrap(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    int _wrap = Int_val(Field(args, 1));
    SetTextureWrap(_texture, _wrap);
    return Val_unit;
}

value raylib_DrawTexture(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    int _posX = Int_val(Field(args, 1));
    int _posY = Int_val(Field(args, 2));
    Color _tint = Colour_val(Field(args, 3));
    DrawTexture(_texture, _posX, _posY, _tint);
    return Val_unit;
}

value raylib_DrawTextureV(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    Vector2 _position = Vector2_val(Field(args, 1));
    Color _tint = Colour_val(Field(args, 2));
    DrawTextureV(_texture, _position, _tint);
    return Val_unit;
}

value raylib_DrawTextureEx(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    Vector2 _position = Vector2_val(Field(args, 1));
    float _rotation = Double_val(Field(args, 2));
    float _scale = Double_val(Field(args, 3));
    Color _tint = Colour_val(Field(args, 4));
    DrawTextureEx(_texture, _position, _rotation, _scale, _tint);
    return Val_unit;
}

value raylib_DrawTextureRec(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    Rectangle _source = Rectangle_val(Field(args, 1));
    Vector2 _position = Vector2_val(Field(args, 2));
    Color _tint = Colour_val(Field(args, 3));
    DrawTextureRec(_texture, _source, _position, _tint);
    return Val_unit;
}

value raylib_DrawTexturePro(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    Rectangle _source = Rectangle_val(Field(args, 1));
    Rectangle _dest = Rectangle_val(Field(args, 2));
    Vector2 _origin = Vector2_val(Field(args, 3));
    float _rotation = Double_val(Field(args, 4));
    Color _tint = Colour_val(Field(args, 5));
    DrawTexturePro(_texture, _source, _dest, _origin, _rotation, _tint);
    return Val_unit;
}

/*
value raylib_DrawTextureNPatch(value args)
{
    Texture2D _texture = Texture_val(Field(args, 0));
    NPatchInfo _nPatchInfo = UNKNOWN(Field(args, 1));
    Rectangle _dest = Rectangle_val(Field(args, 2));
    Vector2 _origin = Vector2_val(Field(args, 3));
    float _rotation = Double_val(Field(args, 4));
    Color _tint = Colour_val(Field(args, 5));
    DrawTextureNPatch(_texture, _nPatchInfo, _dest, _origin, _rotation, _tint);
    return Val_unit;
}
*/

value raylib_ColorIsEqual(value args)
{
    Color _col1 = Colour_val(Field(args, 0));
    Color _col2 = Colour_val(Field(args, 1));
    bool result = ColorIsEqual(_col1, _col2);
    return Val_bool(result);
}

value raylib_Fade(value args)
{
    Color _color = Colour_val(Field(args, 0));
    float _alpha = Double_val(Field(args, 1));
    Color result = Fade(_color, _alpha);
    return Val_colour(result);
}

value raylib_ColorToInt(value arg)
{
    Color _color = Colour_val(arg);
    int result = ColorToInt(_color);
    return Val_int(result);
}

/*
value raylib_ColorNormalize(value arg)
{
    Color _color = Colour_val(arg);
    Vector4 result = ColorNormalize(_color);
    return UNKNOWN(result);
}
*/

/*
value raylib_ColorFromNormalized(value arg)
{
    Vector4 _normalized = UNKNOWN(arg);
    Color result = ColorFromNormalized(_normalized);
    return Val_colour(result);
}
*/

/*
value raylib_ColorToHSV(value arg)
{
    Color _color = Colour_val(arg);
    Vector3 result = ColorToHSV(_color);
    return UNKNOWN(result);
}
*/

value raylib_ColorFromHSV(value args)
{
    float _hue = Double_val(Field(args, 0));
    float _saturation = Double_val(Field(args, 1));
    float _value = Double_val(Field(args, 2));
    Color result = ColorFromHSV(_hue, _saturation, _value);
    return Val_colour(result);
}

value raylib_ColorTint(value args)
{
    Color _color = Colour_val(Field(args, 0));
    Color _tint = Colour_val(Field(args, 1));
    Color result = ColorTint(_color, _tint);
    return Val_colour(result);
}

value raylib_ColorBrightness(value args)
{
    Color _color = Colour_val(Field(args, 0));
    float _factor = Double_val(Field(args, 1));
    Color result = ColorBrightness(_color, _factor);
    return Val_colour(result);
}

value raylib_ColorContrast(value args)
{
    Color _color = Colour_val(Field(args, 0));
    float _contrast = Double_val(Field(args, 1));
    Color result = ColorContrast(_color, _contrast);
    return Val_colour(result);
}

value raylib_ColorAlpha(value args)
{
    Color _color = Colour_val(Field(args, 0));
    float _alpha = Double_val(Field(args, 1));
    Color result = ColorAlpha(_color, _alpha);
    return Val_colour(result);
}

value raylib_ColorAlphaBlend(value args)
{
    Color _dst = Colour_val(Field(args, 0));
    Color _src = Colour_val(Field(args, 1));
    Color _tint = Colour_val(Field(args, 2));
    Color result = ColorAlphaBlend(_dst, _src, _tint);
    return Val_colour(result);
}

value raylib_ColorLerp(value args)
{
    Color _color1 = Colour_val(Field(args, 0));
    Color _color2 = Colour_val(Field(args, 1));
    float _factor = Double_val(Field(args, 2));
    Color result = ColorLerp(_color1, _color2, _factor);
    return Val_colour(result);
}

value raylib_GetColor(value arg)
{
    unsigned int _hexValue = Long_val(arg);
    Color result = GetColor(_hexValue);
    return Val_colour(result);
}

/*
value raylib_GetPixelColor(value args)
{
    void * _srcPtr = UNKNOWN(Field(args, 0));
    int _format = Int_val(Field(args, 1));
    Color result = GetPixelColor(_srcPtr, _format);
    return Val_colour(result);
}
*/

/*
value raylib_SetPixelColor(value args)
{
    void * _dstPtr = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    int _format = Int_val(Field(args, 2));
    SetPixelColor(_dstPtr, _color, _format);
    return Val_unit;
}
*/

value raylib_GetPixelDataSize(value args)
{
    int _width = Int_val(Field(args, 0));
    int _height = Int_val(Field(args, 1));
    int _format = Int_val(Field(args, 2));
    int result = GetPixelDataSize(_width, _height, _format);
    return Val_int(result);
}

/*
value raylib_GetFontDefault(value unit)
{
    Font result = GetFontDefault();
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadFont(value arg)
{
    const char * _fileName = String_val(arg);
    Font result = LoadFont(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadFontEx(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    int _fontSize = Int_val(Field(args, 1));
    int * _codepoints = UNKNOWN(Field(args, 2));
    int _codepointCount = Int_val(Field(args, 3));
    Font result = LoadFontEx(_fileName, _fontSize, _codepoints, _codepointCount);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadFontFromImage(value args)
{
    Image _image = Image_val(Field(args, 0));
    Color _key = Colour_val(Field(args, 1));
    int _firstChar = Int_val(Field(args, 2));
    Font result = LoadFontFromImage(_image, _key, _firstChar);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadFontFromMemory(value args)
{
    const char * _fileType = String_val(Field(args, 0));
    const unsigned char * _fileData = UNKNOWN(Field(args, 1));
    int _dataSize = Int_val(Field(args, 2));
    int _fontSize = Int_val(Field(args, 3));
    int * _codepoints = UNKNOWN(Field(args, 4));
    int _codepointCount = Int_val(Field(args, 5));
    Font result = LoadFontFromMemory(_fileType, _fileData, _dataSize, _fontSize, _codepoints, _codepointCount);
    return UNKNOWN(result);
}
*/

/*
value raylib_IsFontValid(value arg)
{
    Font _font = UNKNOWN(arg);
    bool result = IsFontValid(_font);
    return Val_bool(result);
}
*/

/*
value raylib_LoadFontData(value args)
{
    const unsigned char * _fileData = UNKNOWN(Field(args, 0));
    int _dataSize = Int_val(Field(args, 1));
    int _fontSize = Int_val(Field(args, 2));
    int * _codepoints = UNKNOWN(Field(args, 3));
    int _codepointCount = Int_val(Field(args, 4));
    int _type = Int_val(Field(args, 5));
    GlyphInfo * result = LoadFontData(_fileData, _dataSize, _fontSize, _codepoints, _codepointCount, _type);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageFontAtlas(value args)
{
    const GlyphInfo * _glyphs = UNKNOWN(Field(args, 0));
    Rectangle ** _glyphRecs = UNKNOWN(Field(args, 1));
    int _glyphCount = Int_val(Field(args, 2));
    int _fontSize = Int_val(Field(args, 3));
    int _padding = Int_val(Field(args, 4));
    int _packMethod = Int_val(Field(args, 5));
    Image result = GenImageFontAtlas(_glyphs, _glyphRecs, _glyphCount, _fontSize, _padding, _packMethod);
    return Val_image(result);
}
*/

/*
value raylib_UnloadFontData(value args)
{
    GlyphInfo * _glyphs = UNKNOWN(Field(args, 0));
    int _glyphCount = Int_val(Field(args, 1));
    UnloadFontData(_glyphs, _glyphCount);
    return Val_unit;
}
*/

/*
value raylib_UnloadFont(value arg)
{
    Font _font = UNKNOWN(arg);
    UnloadFont(_font);
    return Val_unit;
}
*/

/*
value raylib_ExportFontAsCode(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportFontAsCode(_font, _fileName);
    return Val_bool(result);
}
*/

value raylib_DrawFPS(value args)
{
    int _posX = Int_val(Field(args, 0));
    int _posY = Int_val(Field(args, 1));
    DrawFPS(_posX, _posY);
    return Val_unit;
}

value raylib_DrawText(value args)
{
    const char * _text = String_val(Field(args, 0));
    int _posX = Int_val(Field(args, 1));
    int _posY = Int_val(Field(args, 2));
    int _fontSize = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawText(_text, _posX, _posY, _fontSize, _color);
    return Val_unit;
}

/*
value raylib_DrawTextEx(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    const char * _text = String_val(Field(args, 1));
    Vector2 _position = Vector2_val(Field(args, 2));
    float _fontSize = Double_val(Field(args, 3));
    float _spacing = Double_val(Field(args, 4));
    Color _tint = Colour_val(Field(args, 5));
    DrawTextEx(_font, _text, _position, _fontSize, _spacing, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawTextPro(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    const char * _text = String_val(Field(args, 1));
    Vector2 _position = Vector2_val(Field(args, 2));
    Vector2 _origin = Vector2_val(Field(args, 3));
    float _rotation = Double_val(Field(args, 4));
    float _fontSize = Double_val(Field(args, 5));
    float _spacing = Double_val(Field(args, 6));
    Color _tint = Colour_val(Field(args, 7));
    DrawTextPro(_font, _text, _position, _origin, _rotation, _fontSize, _spacing, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawTextCodepoint(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    int _codepoint = Int_val(Field(args, 1));
    Vector2 _position = Vector2_val(Field(args, 2));
    float _fontSize = Double_val(Field(args, 3));
    Color _tint = Colour_val(Field(args, 4));
    DrawTextCodepoint(_font, _codepoint, _position, _fontSize, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawTextCodepoints(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    const int * _codepoints = UNKNOWN(Field(args, 1));
    int _codepointCount = Int_val(Field(args, 2));
    Vector2 _position = Vector2_val(Field(args, 3));
    float _fontSize = Double_val(Field(args, 4));
    float _spacing = Double_val(Field(args, 5));
    Color _tint = Colour_val(Field(args, 6));
    DrawTextCodepoints(_font, _codepoints, _codepointCount, _position, _fontSize, _spacing, _tint);
    return Val_unit;
}
*/

value raylib_SetTextLineSpacing(value arg)
{
    int _spacing = Int_val(arg);
    SetTextLineSpacing(_spacing);
    return Val_unit;
}

value raylib_MeasureText(value args)
{
    const char * _text = String_val(Field(args, 0));
    int _fontSize = Int_val(Field(args, 1));
    int result = MeasureText(_text, _fontSize);
    return Val_int(result);
}

/*
value raylib_MeasureTextEx(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    const char * _text = String_val(Field(args, 1));
    float _fontSize = Double_val(Field(args, 2));
    float _spacing = Double_val(Field(args, 3));
    Vector2 result = MeasureTextEx(_font, _text, _fontSize, _spacing);
    return Val_vector2(result);
}
*/

/*
value raylib_GetGlyphIndex(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    int _codepoint = Int_val(Field(args, 1));
    int result = GetGlyphIndex(_font, _codepoint);
    return Val_int(result);
}
*/

/*
value raylib_GetGlyphInfo(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    int _codepoint = Int_val(Field(args, 1));
    GlyphInfo result = GetGlyphInfo(_font, _codepoint);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetGlyphAtlasRec(value args)
{
    Font _font = UNKNOWN(Field(args, 0));
    int _codepoint = Int_val(Field(args, 1));
    Rectangle result = GetGlyphAtlasRec(_font, _codepoint);
    return Val_rectangle(result);
}
*/

/*
value raylib_LoadUTF8(value args)
{
    const int * _codepoints = UNKNOWN(Field(args, 0));
    int _length = Int_val(Field(args, 1));
    char * result = LoadUTF8(_codepoints, _length);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadUTF8(value arg)
{
    char * _text = UNKNOWN(arg);
    UnloadUTF8(_text);
    return Val_unit;
}
*/

/*
value raylib_LoadCodepoints(value args)
{
    const char * _text = String_val(Field(args, 0));
    int * _count = UNKNOWN(Field(args, 1));
    int * result = LoadCodepoints(_text, _count);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadCodepoints(value arg)
{
    int * _codepoints = UNKNOWN(arg);
    UnloadCodepoints(_codepoints);
    return Val_unit;
}
*/

value raylib_GetCodepointCount(value arg)
{
    const char * _text = String_val(arg);
    int result = GetCodepointCount(_text);
    return Val_int(result);
}

/*
value raylib_GetCodepoint(value args)
{
    const char * _text = String_val(Field(args, 0));
    int * _codepointSize = UNKNOWN(Field(args, 1));
    int result = GetCodepoint(_text, _codepointSize);
    return Val_int(result);
}
*/

/*
value raylib_GetCodepointNext(value args)
{
    const char * _text = String_val(Field(args, 0));
    int * _codepointSize = UNKNOWN(Field(args, 1));
    int result = GetCodepointNext(_text, _codepointSize);
    return Val_int(result);
}
*/

/*
value raylib_GetCodepointPrevious(value args)
{
    const char * _text = String_val(Field(args, 0));
    int * _codepointSize = UNKNOWN(Field(args, 1));
    int result = GetCodepointPrevious(_text, _codepointSize);
    return Val_int(result);
}
*/

/*
value raylib_CodepointToUTF8(value args)
{
    int _codepoint = Int_val(Field(args, 0));
    int * _utf8Size = UNKNOWN(Field(args, 1));
    const char * result = CodepointToUTF8(_codepoint, _utf8Size);
    return Val_string(result);
}
*/

/*
value raylib_TextCopy(value args)
{
    char * _dst = UNKNOWN(Field(args, 0));
    const char * _src = String_val(Field(args, 1));
    int result = TextCopy(_dst, _src);
    return Val_int(result);
}
*/

value raylib_TextIsEqual(value args)
{
    const char * _text1 = String_val(Field(args, 0));
    const char * _text2 = String_val(Field(args, 1));
    bool result = TextIsEqual(_text1, _text2);
    return Val_bool(result);
}

value raylib_TextLength(value arg)
{
    const char * _text = String_val(arg);
    unsigned int result = TextLength(_text);
    return Val_long(result);
}

/*
value raylib_TextFormat(value args)
{
    const char * _text = String_val(Field(args, 0));
    ... _args = UNKNOWN(Field(args, 1));
    const char * result = TextFormat(_text, _args);
    return Val_string(result);
}
*/

value raylib_TextSubtext(value args)
{
    const char * _text = String_val(Field(args, 0));
    int _position = Int_val(Field(args, 1));
    int _length = Int_val(Field(args, 2));
    const char * result = TextSubtext(_text, _position, _length);
    return Val_string(result);
}

/*
value raylib_TextReplace(value args)
{
    const char * _text = String_val(Field(args, 0));
    const char * _replace = String_val(Field(args, 1));
    const char * _by = String_val(Field(args, 2));
    char * result = TextReplace(_text, _replace, _by);
    return UNKNOWN(result);
}
*/

/*
value raylib_TextInsert(value args)
{
    const char * _text = String_val(Field(args, 0));
    const char * _insert = String_val(Field(args, 1));
    int _position = Int_val(Field(args, 2));
    char * result = TextInsert(_text, _insert, _position);
    return UNKNOWN(result);
}
*/

/*
value raylib_TextJoin(value args)
{
    const char ** _textList = UNKNOWN(Field(args, 0));
    int _count = Int_val(Field(args, 1));
    const char * _delimiter = String_val(Field(args, 2));
    const char * result = TextJoin(_textList, _count, _delimiter);
    return Val_string(result);
}
*/

/*
value raylib_TextSplit(value args)
{
    const char * _text = String_val(Field(args, 0));
    char _delimiter = UNKNOWN(Field(args, 1));
    int * _count = UNKNOWN(Field(args, 2));
    const char ** result = TextSplit(_text, _delimiter, _count);
    return UNKNOWN(result);
}
*/

/*
value raylib_TextAppend(value args)
{
    char * _text = UNKNOWN(Field(args, 0));
    const char * _append = String_val(Field(args, 1));
    int * _position = UNKNOWN(Field(args, 2));
    TextAppend(_text, _append, _position);
    return Val_unit;
}
*/

value raylib_TextFindIndex(value args)
{
    const char * _text = String_val(Field(args, 0));
    const char * _find = String_val(Field(args, 1));
    int result = TextFindIndex(_text, _find);
    return Val_int(result);
}

value raylib_TextToUpper(value arg)
{
    const char * _text = String_val(arg);
    const char * result = TextToUpper(_text);
    return Val_string(result);
}

value raylib_TextToLower(value arg)
{
    const char * _text = String_val(arg);
    const char * result = TextToLower(_text);
    return Val_string(result);
}

value raylib_TextToPascal(value arg)
{
    const char * _text = String_val(arg);
    const char * result = TextToPascal(_text);
    return Val_string(result);
}

value raylib_TextToSnake(value arg)
{
    const char * _text = String_val(arg);
    const char * result = TextToSnake(_text);
    return Val_string(result);
}

value raylib_TextToCamel(value arg)
{
    const char * _text = String_val(arg);
    const char * result = TextToCamel(_text);
    return Val_string(result);
}

value raylib_TextToInteger(value arg)
{
    const char * _text = String_val(arg);
    int result = TextToInteger(_text);
    return Val_int(result);
}

value raylib_TextToFloat(value arg)
{
    const char * _text = String_val(arg);
    float result = TextToFloat(_text);
    return copy_double(result);
}

/*
value raylib_DrawLine3D(value args)
{
    Vector3 _startPos = UNKNOWN(Field(args, 0));
    Vector3 _endPos = UNKNOWN(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawLine3D(_startPos, _endPos, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawPoint3D(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    DrawPoint3D(_position, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCircle3D(value args)
{
    Vector3 _center = UNKNOWN(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    Vector3 _rotationAxis = UNKNOWN(Field(args, 2));
    float _rotationAngle = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawCircle3D(_center, _radius, _rotationAxis, _rotationAngle, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawTriangle3D(value args)
{
    Vector3 _v1 = UNKNOWN(Field(args, 0));
    Vector3 _v2 = UNKNOWN(Field(args, 1));
    Vector3 _v3 = UNKNOWN(Field(args, 2));
    Color _color = Colour_val(Field(args, 3));
    DrawTriangle3D(_v1, _v2, _v3, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawTriangleStrip3D(value args)
{
    const Vector3 * _points = UNKNOWN(Field(args, 0));
    int _pointCount = Int_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawTriangleStrip3D(_points, _pointCount, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCube(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    float _width = Double_val(Field(args, 1));
    float _height = Double_val(Field(args, 2));
    float _length = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawCube(_position, _width, _height, _length, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCubeV(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    Vector3 _size = UNKNOWN(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawCubeV(_position, _size, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCubeWires(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    float _width = Double_val(Field(args, 1));
    float _height = Double_val(Field(args, 2));
    float _length = Double_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawCubeWires(_position, _width, _height, _length, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCubeWiresV(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    Vector3 _size = UNKNOWN(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawCubeWiresV(_position, _size, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawSphere(value args)
{
    Vector3 _centerPos = UNKNOWN(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawSphere(_centerPos, _radius, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawSphereEx(value args)
{
    Vector3 _centerPos = UNKNOWN(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    int _rings = Int_val(Field(args, 2));
    int _slices = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawSphereEx(_centerPos, _radius, _rings, _slices, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawSphereWires(value args)
{
    Vector3 _centerPos = UNKNOWN(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    int _rings = Int_val(Field(args, 2));
    int _slices = Int_val(Field(args, 3));
    Color _color = Colour_val(Field(args, 4));
    DrawSphereWires(_centerPos, _radius, _rings, _slices, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCylinder(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    float _radiusTop = Double_val(Field(args, 1));
    float _radiusBottom = Double_val(Field(args, 2));
    float _height = Double_val(Field(args, 3));
    int _slices = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCylinder(_position, _radiusTop, _radiusBottom, _height, _slices, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCylinderEx(value args)
{
    Vector3 _startPos = UNKNOWN(Field(args, 0));
    Vector3 _endPos = UNKNOWN(Field(args, 1));
    float _startRadius = Double_val(Field(args, 2));
    float _endRadius = Double_val(Field(args, 3));
    int _sides = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCylinderEx(_startPos, _endPos, _startRadius, _endRadius, _sides, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCylinderWires(value args)
{
    Vector3 _position = UNKNOWN(Field(args, 0));
    float _radiusTop = Double_val(Field(args, 1));
    float _radiusBottom = Double_val(Field(args, 2));
    float _height = Double_val(Field(args, 3));
    int _slices = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCylinderWires(_position, _radiusTop, _radiusBottom, _height, _slices, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCylinderWiresEx(value args)
{
    Vector3 _startPos = UNKNOWN(Field(args, 0));
    Vector3 _endPos = UNKNOWN(Field(args, 1));
    float _startRadius = Double_val(Field(args, 2));
    float _endRadius = Double_val(Field(args, 3));
    int _sides = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCylinderWiresEx(_startPos, _endPos, _startRadius, _endRadius, _sides, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCapsule(value args)
{
    Vector3 _startPos = UNKNOWN(Field(args, 0));
    Vector3 _endPos = UNKNOWN(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    int _slices = Int_val(Field(args, 3));
    int _rings = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCapsule(_startPos, _endPos, _radius, _slices, _rings, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawCapsuleWires(value args)
{
    Vector3 _startPos = UNKNOWN(Field(args, 0));
    Vector3 _endPos = UNKNOWN(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    int _slices = Int_val(Field(args, 3));
    int _rings = Int_val(Field(args, 4));
    Color _color = Colour_val(Field(args, 5));
    DrawCapsuleWires(_startPos, _endPos, _radius, _slices, _rings, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawPlane(value args)
{
    Vector3 _centerPos = UNKNOWN(Field(args, 0));
    Vector2 _size = Vector2_val(Field(args, 1));
    Color _color = Colour_val(Field(args, 2));
    DrawPlane(_centerPos, _size, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawRay(value args)
{
    Ray _ray = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    DrawRay(_ray, _color);
    return Val_unit;
}
*/

value raylib_DrawGrid(value args)
{
    int _slices = Int_val(Field(args, 0));
    float _spacing = Double_val(Field(args, 1));
    DrawGrid(_slices, _spacing);
    return Val_unit;
}

/*
value raylib_LoadModel(value arg)
{
    const char * _fileName = String_val(arg);
    Model result = LoadModel(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadModelFromMesh(value arg)
{
    Mesh _mesh = UNKNOWN(arg);
    Model result = LoadModelFromMesh(_mesh);
    return UNKNOWN(result);
}
*/

/*
value raylib_IsModelValid(value arg)
{
    Model _model = UNKNOWN(arg);
    bool result = IsModelValid(_model);
    return Val_bool(result);
}
*/

/*
value raylib_UnloadModel(value arg)
{
    Model _model = UNKNOWN(arg);
    UnloadModel(_model);
    return Val_unit;
}
*/

/*
value raylib_GetModelBoundingBox(value arg)
{
    Model _model = UNKNOWN(arg);
    BoundingBox result = GetModelBoundingBox(_model);
    return UNKNOWN(result);
}
*/

/*
value raylib_DrawModel(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    Vector3 _position = UNKNOWN(Field(args, 1));
    float _scale = Double_val(Field(args, 2));
    Color _tint = Colour_val(Field(args, 3));
    DrawModel(_model, _position, _scale, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawModelEx(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    Vector3 _position = UNKNOWN(Field(args, 1));
    Vector3 _rotationAxis = UNKNOWN(Field(args, 2));
    float _rotationAngle = Double_val(Field(args, 3));
    Vector3 _scale = UNKNOWN(Field(args, 4));
    Color _tint = Colour_val(Field(args, 5));
    DrawModelEx(_model, _position, _rotationAxis, _rotationAngle, _scale, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawModelWires(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    Vector3 _position = UNKNOWN(Field(args, 1));
    float _scale = Double_val(Field(args, 2));
    Color _tint = Colour_val(Field(args, 3));
    DrawModelWires(_model, _position, _scale, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawModelWiresEx(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    Vector3 _position = UNKNOWN(Field(args, 1));
    Vector3 _rotationAxis = UNKNOWN(Field(args, 2));
    float _rotationAngle = Double_val(Field(args, 3));
    Vector3 _scale = UNKNOWN(Field(args, 4));
    Color _tint = Colour_val(Field(args, 5));
    DrawModelWiresEx(_model, _position, _rotationAxis, _rotationAngle, _scale, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawModelPoints(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    Vector3 _position = UNKNOWN(Field(args, 1));
    float _scale = Double_val(Field(args, 2));
    Color _tint = Colour_val(Field(args, 3));
    DrawModelPoints(_model, _position, _scale, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawModelPointsEx(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    Vector3 _position = UNKNOWN(Field(args, 1));
    Vector3 _rotationAxis = UNKNOWN(Field(args, 2));
    float _rotationAngle = Double_val(Field(args, 3));
    Vector3 _scale = UNKNOWN(Field(args, 4));
    Color _tint = Colour_val(Field(args, 5));
    DrawModelPointsEx(_model, _position, _rotationAxis, _rotationAngle, _scale, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawBoundingBox(value args)
{
    BoundingBox _box = UNKNOWN(Field(args, 0));
    Color _color = Colour_val(Field(args, 1));
    DrawBoundingBox(_box, _color);
    return Val_unit;
}
*/

/*
value raylib_DrawBillboard(value args)
{
    Camera _camera = UNKNOWN(Field(args, 0));
    Texture2D _texture = Texture_val(Field(args, 1));
    Vector3 _position = UNKNOWN(Field(args, 2));
    float _scale = Double_val(Field(args, 3));
    Color _tint = Colour_val(Field(args, 4));
    DrawBillboard(_camera, _texture, _position, _scale, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawBillboardRec(value args)
{
    Camera _camera = UNKNOWN(Field(args, 0));
    Texture2D _texture = Texture_val(Field(args, 1));
    Rectangle _source = Rectangle_val(Field(args, 2));
    Vector3 _position = UNKNOWN(Field(args, 3));
    Vector2 _size = Vector2_val(Field(args, 4));
    Color _tint = Colour_val(Field(args, 5));
    DrawBillboardRec(_camera, _texture, _source, _position, _size, _tint);
    return Val_unit;
}
*/

/*
value raylib_DrawBillboardPro(value args)
{
    Camera _camera = UNKNOWN(Field(args, 0));
    Texture2D _texture = Texture_val(Field(args, 1));
    Rectangle _source = Rectangle_val(Field(args, 2));
    Vector3 _position = UNKNOWN(Field(args, 3));
    Vector3 _up = UNKNOWN(Field(args, 4));
    Vector2 _size = Vector2_val(Field(args, 5));
    Vector2 _origin = Vector2_val(Field(args, 6));
    float _rotation = Double_val(Field(args, 7));
    Color _tint = Colour_val(Field(args, 8));
    DrawBillboardPro(_camera, _texture, _source, _position, _up, _size, _origin, _rotation, _tint);
    return Val_unit;
}
*/

/*
value raylib_UploadMesh(value args)
{
    Mesh * _mesh = UNKNOWN(Field(args, 0));
    bool _dynamic = Bool_val(Field(args, 1));
    UploadMesh(_mesh, _dynamic);
    return Val_unit;
}
*/

/*
value raylib_UpdateMeshBuffer(value args)
{
    Mesh _mesh = UNKNOWN(Field(args, 0));
    int _index = Int_val(Field(args, 1));
    const void * _data = UNKNOWN(Field(args, 2));
    int _dataSize = Int_val(Field(args, 3));
    int _offset = Int_val(Field(args, 4));
    UpdateMeshBuffer(_mesh, _index, _data, _dataSize, _offset);
    return Val_unit;
}
*/

/*
value raylib_UnloadMesh(value arg)
{
    Mesh _mesh = UNKNOWN(arg);
    UnloadMesh(_mesh);
    return Val_unit;
}
*/

/*
value raylib_DrawMesh(value args)
{
    Mesh _mesh = UNKNOWN(Field(args, 0));
    Material _material = UNKNOWN(Field(args, 1));
    Matrix _transform = UNKNOWN(Field(args, 2));
    DrawMesh(_mesh, _material, _transform);
    return Val_unit;
}
*/

/*
value raylib_DrawMeshInstanced(value args)
{
    Mesh _mesh = UNKNOWN(Field(args, 0));
    Material _material = UNKNOWN(Field(args, 1));
    const Matrix * _transforms = UNKNOWN(Field(args, 2));
    int _instances = Int_val(Field(args, 3));
    DrawMeshInstanced(_mesh, _material, _transforms, _instances);
    return Val_unit;
}
*/

/*
value raylib_GetMeshBoundingBox(value arg)
{
    Mesh _mesh = UNKNOWN(arg);
    BoundingBox result = GetMeshBoundingBox(_mesh);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshTangents(value arg)
{
    Mesh * _mesh = UNKNOWN(arg);
    GenMeshTangents(_mesh);
    return Val_unit;
}
*/

/*
value raylib_ExportMesh(value args)
{
    Mesh _mesh = UNKNOWN(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportMesh(_mesh, _fileName);
    return Val_bool(result);
}
*/

/*
value raylib_ExportMeshAsCode(value args)
{
    Mesh _mesh = UNKNOWN(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportMeshAsCode(_mesh, _fileName);
    return Val_bool(result);
}
*/

/*
value raylib_GenMeshPoly(value args)
{
    int _sides = Int_val(Field(args, 0));
    float _radius = Double_val(Field(args, 1));
    Mesh result = GenMeshPoly(_sides, _radius);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshPlane(value args)
{
    float _width = Double_val(Field(args, 0));
    float _length = Double_val(Field(args, 1));
    int _resX = Int_val(Field(args, 2));
    int _resZ = Int_val(Field(args, 3));
    Mesh result = GenMeshPlane(_width, _length, _resX, _resZ);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCube(value args)
{
    float _width = Double_val(Field(args, 0));
    float _height = Double_val(Field(args, 1));
    float _length = Double_val(Field(args, 2));
    Mesh result = GenMeshCube(_width, _height, _length);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshSphere(value args)
{
    float _radius = Double_val(Field(args, 0));
    int _rings = Int_val(Field(args, 1));
    int _slices = Int_val(Field(args, 2));
    Mesh result = GenMeshSphere(_radius, _rings, _slices);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshHemiSphere(value args)
{
    float _radius = Double_val(Field(args, 0));
    int _rings = Int_val(Field(args, 1));
    int _slices = Int_val(Field(args, 2));
    Mesh result = GenMeshHemiSphere(_radius, _rings, _slices);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCylinder(value args)
{
    float _radius = Double_val(Field(args, 0));
    float _height = Double_val(Field(args, 1));
    int _slices = Int_val(Field(args, 2));
    Mesh result = GenMeshCylinder(_radius, _height, _slices);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCone(value args)
{
    float _radius = Double_val(Field(args, 0));
    float _height = Double_val(Field(args, 1));
    int _slices = Int_val(Field(args, 2));
    Mesh result = GenMeshCone(_radius, _height, _slices);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshTorus(value args)
{
    float _radius = Double_val(Field(args, 0));
    float _size = Double_val(Field(args, 1));
    int _radSeg = Int_val(Field(args, 2));
    int _sides = Int_val(Field(args, 3));
    Mesh result = GenMeshTorus(_radius, _size, _radSeg, _sides);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshKnot(value args)
{
    float _radius = Double_val(Field(args, 0));
    float _size = Double_val(Field(args, 1));
    int _radSeg = Int_val(Field(args, 2));
    int _sides = Int_val(Field(args, 3));
    Mesh result = GenMeshKnot(_radius, _size, _radSeg, _sides);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshHeightmap(value args)
{
    Image _heightmap = Image_val(Field(args, 0));
    Vector3 _size = UNKNOWN(Field(args, 1));
    Mesh result = GenMeshHeightmap(_heightmap, _size);
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCubicmap(value args)
{
    Image _cubicmap = Image_val(Field(args, 0));
    Vector3 _cubeSize = UNKNOWN(Field(args, 1));
    Mesh result = GenMeshCubicmap(_cubicmap, _cubeSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadMaterials(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    int * _materialCount = UNKNOWN(Field(args, 1));
    Material * result = LoadMaterials(_fileName, _materialCount);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadMaterialDefault(value unit)
{
    Material result = LoadMaterialDefault();
    return UNKNOWN(result);
}
*/

/*
value raylib_IsMaterialValid(value arg)
{
    Material _material = UNKNOWN(arg);
    bool result = IsMaterialValid(_material);
    return Val_bool(result);
}
*/

/*
value raylib_UnloadMaterial(value arg)
{
    Material _material = UNKNOWN(arg);
    UnloadMaterial(_material);
    return Val_unit;
}
*/

/*
value raylib_SetMaterialTexture(value args)
{
    Material * _material = UNKNOWN(Field(args, 0));
    int _mapType = Int_val(Field(args, 1));
    Texture2D _texture = Texture_val(Field(args, 2));
    SetMaterialTexture(_material, _mapType, _texture);
    return Val_unit;
}
*/

/*
value raylib_SetModelMeshMaterial(value args)
{
    Model * _model = UNKNOWN(Field(args, 0));
    int _meshId = Int_val(Field(args, 1));
    int _materialId = Int_val(Field(args, 2));
    SetModelMeshMaterial(_model, _meshId, _materialId);
    return Val_unit;
}
*/

/*
value raylib_LoadModelAnimations(value args)
{
    const char * _fileName = String_val(Field(args, 0));
    int * _animCount = UNKNOWN(Field(args, 1));
    ModelAnimation * result = LoadModelAnimations(_fileName, _animCount);
    return UNKNOWN(result);
}
*/

/*
value raylib_UpdateModelAnimation(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    ModelAnimation _anim = UNKNOWN(Field(args, 1));
    int _frame = Int_val(Field(args, 2));
    UpdateModelAnimation(_model, _anim, _frame);
    return Val_unit;
}
*/

/*
value raylib_UpdateModelAnimationBones(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    ModelAnimation _anim = UNKNOWN(Field(args, 1));
    int _frame = Int_val(Field(args, 2));
    UpdateModelAnimationBones(_model, _anim, _frame);
    return Val_unit;
}
*/

/*
value raylib_UnloadModelAnimation(value arg)
{
    ModelAnimation _anim = UNKNOWN(arg);
    UnloadModelAnimation(_anim);
    return Val_unit;
}
*/

/*
value raylib_UnloadModelAnimations(value args)
{
    ModelAnimation * _animations = UNKNOWN(Field(args, 0));
    int _animCount = Int_val(Field(args, 1));
    UnloadModelAnimations(_animations, _animCount);
    return Val_unit;
}
*/

/*
value raylib_IsModelAnimationValid(value args)
{
    Model _model = UNKNOWN(Field(args, 0));
    ModelAnimation _anim = UNKNOWN(Field(args, 1));
    bool result = IsModelAnimationValid(_model, _anim);
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionSpheres(value args)
{
    Vector3 _center1 = UNKNOWN(Field(args, 0));
    float _radius1 = Double_val(Field(args, 1));
    Vector3 _center2 = UNKNOWN(Field(args, 2));
    float _radius2 = Double_val(Field(args, 3));
    bool result = CheckCollisionSpheres(_center1, _radius1, _center2, _radius2);
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionBoxes(value args)
{
    BoundingBox _box1 = UNKNOWN(Field(args, 0));
    BoundingBox _box2 = UNKNOWN(Field(args, 1));
    bool result = CheckCollisionBoxes(_box1, _box2);
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionBoxSphere(value args)
{
    BoundingBox _box = UNKNOWN(Field(args, 0));
    Vector3 _center = UNKNOWN(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    bool result = CheckCollisionBoxSphere(_box, _center, _radius);
    return Val_bool(result);
}
*/

/*
value raylib_GetRayCollisionSphere(value args)
{
    Ray _ray = UNKNOWN(Field(args, 0));
    Vector3 _center = UNKNOWN(Field(args, 1));
    float _radius = Double_val(Field(args, 2));
    RayCollision result = GetRayCollisionSphere(_ray, _center, _radius);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionBox(value args)
{
    Ray _ray = UNKNOWN(Field(args, 0));
    BoundingBox _box = UNKNOWN(Field(args, 1));
    RayCollision result = GetRayCollisionBox(_ray, _box);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionMesh(value args)
{
    Ray _ray = UNKNOWN(Field(args, 0));
    Mesh _mesh = UNKNOWN(Field(args, 1));
    Matrix _transform = UNKNOWN(Field(args, 2));
    RayCollision result = GetRayCollisionMesh(_ray, _mesh, _transform);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionTriangle(value args)
{
    Ray _ray = UNKNOWN(Field(args, 0));
    Vector3 _p1 = UNKNOWN(Field(args, 1));
    Vector3 _p2 = UNKNOWN(Field(args, 2));
    Vector3 _p3 = UNKNOWN(Field(args, 3));
    RayCollision result = GetRayCollisionTriangle(_ray, _p1, _p2, _p3);
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionQuad(value args)
{
    Ray _ray = UNKNOWN(Field(args, 0));
    Vector3 _p1 = UNKNOWN(Field(args, 1));
    Vector3 _p2 = UNKNOWN(Field(args, 2));
    Vector3 _p3 = UNKNOWN(Field(args, 3));
    Vector3 _p4 = UNKNOWN(Field(args, 4));
    RayCollision result = GetRayCollisionQuad(_ray, _p1, _p2, _p3, _p4);
    return UNKNOWN(result);
}
*/

value raylib_InitAudioDevice(value unit)
{
    InitAudioDevice();
    return Val_unit;
}

value raylib_CloseAudioDevice(value unit)
{
    CloseAudioDevice();
    return Val_unit;
}

value raylib_IsAudioDeviceReady(value unit)
{
    bool result = IsAudioDeviceReady();
    return Val_bool(result);
}

value raylib_SetMasterVolume(value arg)
{
    float _volume = Double_val(arg);
    SetMasterVolume(_volume);
    return Val_unit;
}

value raylib_GetMasterVolume(value unit)
{
    float result = GetMasterVolume();
    return copy_double(result);
}

/*
value raylib_LoadWave(value arg)
{
    const char * _fileName = String_val(arg);
    Wave result = LoadWave(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadWaveFromMemory(value args)
{
    const char * _fileType = String_val(Field(args, 0));
    const unsigned char * _fileData = UNKNOWN(Field(args, 1));
    int _dataSize = Int_val(Field(args, 2));
    Wave result = LoadWaveFromMemory(_fileType, _fileData, _dataSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_IsWaveValid(value arg)
{
    Wave _wave = UNKNOWN(arg);
    bool result = IsWaveValid(_wave);
    return Val_bool(result);
}
*/

/*
value raylib_LoadSound(value arg)
{
    const char * _fileName = String_val(arg);
    Sound result = LoadSound(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadSoundFromWave(value arg)
{
    Wave _wave = UNKNOWN(arg);
    Sound result = LoadSoundFromWave(_wave);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadSoundAlias(value arg)
{
    Sound _source = UNKNOWN(arg);
    Sound result = LoadSoundAlias(_source);
    return UNKNOWN(result);
}
*/

/*
value raylib_IsSoundValid(value arg)
{
    Sound _sound = UNKNOWN(arg);
    bool result = IsSoundValid(_sound);
    return Val_bool(result);
}
*/

/*
value raylib_UpdateSound(value args)
{
    Sound _sound = UNKNOWN(Field(args, 0));
    const void * _data = UNKNOWN(Field(args, 1));
    int _sampleCount = Int_val(Field(args, 2));
    UpdateSound(_sound, _data, _sampleCount);
    return Val_unit;
}
*/

/*
value raylib_UnloadWave(value arg)
{
    Wave _wave = UNKNOWN(arg);
    UnloadWave(_wave);
    return Val_unit;
}
*/

/*
value raylib_UnloadSound(value arg)
{
    Sound _sound = UNKNOWN(arg);
    UnloadSound(_sound);
    return Val_unit;
}
*/

/*
value raylib_UnloadSoundAlias(value arg)
{
    Sound _alias = UNKNOWN(arg);
    UnloadSoundAlias(_alias);
    return Val_unit;
}
*/

/*
value raylib_ExportWave(value args)
{
    Wave _wave = UNKNOWN(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportWave(_wave, _fileName);
    return Val_bool(result);
}
*/

/*
value raylib_ExportWaveAsCode(value args)
{
    Wave _wave = UNKNOWN(Field(args, 0));
    const char * _fileName = String_val(Field(args, 1));
    bool result = ExportWaveAsCode(_wave, _fileName);
    return Val_bool(result);
}
*/

/*
value raylib_PlaySound(value arg)
{
    Sound _sound = UNKNOWN(arg);
    PlaySound(_sound);
    return Val_unit;
}
*/

/*
value raylib_StopSound(value arg)
{
    Sound _sound = UNKNOWN(arg);
    StopSound(_sound);
    return Val_unit;
}
*/

/*
value raylib_PauseSound(value arg)
{
    Sound _sound = UNKNOWN(arg);
    PauseSound(_sound);
    return Val_unit;
}
*/

/*
value raylib_ResumeSound(value arg)
{
    Sound _sound = UNKNOWN(arg);
    ResumeSound(_sound);
    return Val_unit;
}
*/

/*
value raylib_IsSoundPlaying(value arg)
{
    Sound _sound = UNKNOWN(arg);
    bool result = IsSoundPlaying(_sound);
    return Val_bool(result);
}
*/

/*
value raylib_SetSoundVolume(value args)
{
    Sound _sound = UNKNOWN(Field(args, 0));
    float _volume = Double_val(Field(args, 1));
    SetSoundVolume(_sound, _volume);
    return Val_unit;
}
*/

/*
value raylib_SetSoundPitch(value args)
{
    Sound _sound = UNKNOWN(Field(args, 0));
    float _pitch = Double_val(Field(args, 1));
    SetSoundPitch(_sound, _pitch);
    return Val_unit;
}
*/

/*
value raylib_SetSoundPan(value args)
{
    Sound _sound = UNKNOWN(Field(args, 0));
    float _pan = Double_val(Field(args, 1));
    SetSoundPan(_sound, _pan);
    return Val_unit;
}
*/

/*
value raylib_WaveCopy(value arg)
{
    Wave _wave = UNKNOWN(arg);
    Wave result = WaveCopy(_wave);
    return UNKNOWN(result);
}
*/

/*
value raylib_WaveCrop(value args)
{
    Wave * _wave = UNKNOWN(Field(args, 0));
    int _initFrame = Int_val(Field(args, 1));
    int _finalFrame = Int_val(Field(args, 2));
    WaveCrop(_wave, _initFrame, _finalFrame);
    return Val_unit;
}
*/

/*
value raylib_WaveFormat(value args)
{
    Wave * _wave = UNKNOWN(Field(args, 0));
    int _sampleRate = Int_val(Field(args, 1));
    int _sampleSize = Int_val(Field(args, 2));
    int _channels = Int_val(Field(args, 3));
    WaveFormat(_wave, _sampleRate, _sampleSize, _channels);
    return Val_unit;
}
*/

/*
value raylib_LoadWaveSamples(value arg)
{
    Wave _wave = UNKNOWN(arg);
    float * result = LoadWaveSamples(_wave);
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadWaveSamples(value arg)
{
    float * _samples = UNKNOWN(arg);
    UnloadWaveSamples(_samples);
    return Val_unit;
}
*/

/*
value raylib_LoadMusicStream(value arg)
{
    const char * _fileName = String_val(arg);
    Music result = LoadMusicStream(_fileName);
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadMusicStreamFromMemory(value args)
{
    const char * _fileType = String_val(Field(args, 0));
    const unsigned char * _data = UNKNOWN(Field(args, 1));
    int _dataSize = Int_val(Field(args, 2));
    Music result = LoadMusicStreamFromMemory(_fileType, _data, _dataSize);
    return UNKNOWN(result);
}
*/

/*
value raylib_IsMusicValid(value arg)
{
    Music _music = UNKNOWN(arg);
    bool result = IsMusicValid(_music);
    return Val_bool(result);
}
*/

/*
value raylib_UnloadMusicStream(value arg)
{
    Music _music = UNKNOWN(arg);
    UnloadMusicStream(_music);
    return Val_unit;
}
*/

/*
value raylib_PlayMusicStream(value arg)
{
    Music _music = UNKNOWN(arg);
    PlayMusicStream(_music);
    return Val_unit;
}
*/

/*
value raylib_IsMusicStreamPlaying(value arg)
{
    Music _music = UNKNOWN(arg);
    bool result = IsMusicStreamPlaying(_music);
    return Val_bool(result);
}
*/

/*
value raylib_UpdateMusicStream(value arg)
{
    Music _music = UNKNOWN(arg);
    UpdateMusicStream(_music);
    return Val_unit;
}
*/

/*
value raylib_StopMusicStream(value arg)
{
    Music _music = UNKNOWN(arg);
    StopMusicStream(_music);
    return Val_unit;
}
*/

/*
value raylib_PauseMusicStream(value arg)
{
    Music _music = UNKNOWN(arg);
    PauseMusicStream(_music);
    return Val_unit;
}
*/

/*
value raylib_ResumeMusicStream(value arg)
{
    Music _music = UNKNOWN(arg);
    ResumeMusicStream(_music);
    return Val_unit;
}
*/

/*
value raylib_SeekMusicStream(value args)
{
    Music _music = UNKNOWN(Field(args, 0));
    float _position = Double_val(Field(args, 1));
    SeekMusicStream(_music, _position);
    return Val_unit;
}
*/

/*
value raylib_SetMusicVolume(value args)
{
    Music _music = UNKNOWN(Field(args, 0));
    float _volume = Double_val(Field(args, 1));
    SetMusicVolume(_music, _volume);
    return Val_unit;
}
*/

/*
value raylib_SetMusicPitch(value args)
{
    Music _music = UNKNOWN(Field(args, 0));
    float _pitch = Double_val(Field(args, 1));
    SetMusicPitch(_music, _pitch);
    return Val_unit;
}
*/

/*
value raylib_SetMusicPan(value args)
{
    Music _music = UNKNOWN(Field(args, 0));
    float _pan = Double_val(Field(args, 1));
    SetMusicPan(_music, _pan);
    return Val_unit;
}
*/

/*
value raylib_GetMusicTimeLength(value arg)
{
    Music _music = UNKNOWN(arg);
    float result = GetMusicTimeLength(_music);
    return copy_double(result);
}
*/

/*
value raylib_GetMusicTimePlayed(value arg)
{
    Music _music = UNKNOWN(arg);
    float result = GetMusicTimePlayed(_music);
    return copy_double(result);
}
*/

/*
value raylib_LoadAudioStream(value args)
{
    unsigned int _sampleRate = Long_val(Field(args, 0));
    unsigned int _sampleSize = Long_val(Field(args, 1));
    unsigned int _channels = Long_val(Field(args, 2));
    AudioStream result = LoadAudioStream(_sampleRate, _sampleSize, _channels);
    return UNKNOWN(result);
}
*/

/*
value raylib_IsAudioStreamValid(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    bool result = IsAudioStreamValid(_stream);
    return Val_bool(result);
}
*/

/*
value raylib_UnloadAudioStream(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    UnloadAudioStream(_stream);
    return Val_unit;
}
*/

/*
value raylib_UpdateAudioStream(value args)
{
    AudioStream _stream = UNKNOWN(Field(args, 0));
    const void * _data = UNKNOWN(Field(args, 1));
    int _frameCount = Int_val(Field(args, 2));
    UpdateAudioStream(_stream, _data, _frameCount);
    return Val_unit;
}
*/

/*
value raylib_IsAudioStreamProcessed(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    bool result = IsAudioStreamProcessed(_stream);
    return Val_bool(result);
}
*/

/*
value raylib_PlayAudioStream(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    PlayAudioStream(_stream);
    return Val_unit;
}
*/

/*
value raylib_PauseAudioStream(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    PauseAudioStream(_stream);
    return Val_unit;
}
*/

/*
value raylib_ResumeAudioStream(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    ResumeAudioStream(_stream);
    return Val_unit;
}
*/

/*
value raylib_IsAudioStreamPlaying(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    bool result = IsAudioStreamPlaying(_stream);
    return Val_bool(result);
}
*/

/*
value raylib_StopAudioStream(value arg)
{
    AudioStream _stream = UNKNOWN(arg);
    StopAudioStream(_stream);
    return Val_unit;
}
*/

/*
value raylib_SetAudioStreamVolume(value args)
{
    AudioStream _stream = UNKNOWN(Field(args, 0));
    float _volume = Double_val(Field(args, 1));
    SetAudioStreamVolume(_stream, _volume);
    return Val_unit;
}
*/

/*
value raylib_SetAudioStreamPitch(value args)
{
    AudioStream _stream = UNKNOWN(Field(args, 0));
    float _pitch = Double_val(Field(args, 1));
    SetAudioStreamPitch(_stream, _pitch);
    return Val_unit;
}
*/

/*
value raylib_SetAudioStreamPan(value args)
{
    AudioStream _stream = UNKNOWN(Field(args, 0));
    float _pan = Double_val(Field(args, 1));
    SetAudioStreamPan(_stream, _pan);
    return Val_unit;
}
*/

value raylib_SetAudioStreamBufferSizeDefault(value arg)
{
    int _size = Int_val(arg);
    SetAudioStreamBufferSizeDefault(_size);
    return Val_unit;
}

/*
value raylib_SetAudioStreamCallback(value args)
{
    AudioStream _stream = UNKNOWN(Field(args, 0));
    AudioCallback _callback = UNKNOWN(Field(args, 1));
    SetAudioStreamCallback(_stream, _callback);
    return Val_unit;
}
*/

/*
value raylib_AttachAudioStreamProcessor(value args)
{
    AudioStream _stream = UNKNOWN(Field(args, 0));
    AudioCallback _processor = UNKNOWN(Field(args, 1));
    AttachAudioStreamProcessor(_stream, _processor);
    return Val_unit;
}
*/

/*
value raylib_DetachAudioStreamProcessor(value args)
{
    AudioStream _stream = UNKNOWN(Field(args, 0));
    AudioCallback _processor = UNKNOWN(Field(args, 1));
    DetachAudioStreamProcessor(_stream, _processor);
    return Val_unit;
}
*/

/*
value raylib_AttachAudioMixedProcessor(value arg)
{
    AudioCallback _processor = UNKNOWN(arg);
    AttachAudioMixedProcessor(_processor);
    return Val_unit;
}
*/

/*
value raylib_DetachAudioMixedProcessor(value arg)
{
    AudioCallback _processor = UNKNOWN(arg);
    DetachAudioMixedProcessor(_processor);
    return Val_unit;
}
*/

