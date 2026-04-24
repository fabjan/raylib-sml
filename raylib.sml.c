#include <string.h>
#include "mlvalues.h"
#include "alloc.h"
#include "raylib.h"

static inline value Val_string(const char *s)
{
    int len = strlen(s);
    value res = alloc_string(len);
    bcopy(s, &Byte(res, 0), len);
    return res;
}

static inline value Val_color(Color c)
{
    return Val_int(*(int*)&c);
}

static inline Color Color_val(value v)
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

value raylib_InitWindow(value width, value height, value title)
{
    InitWindow(Int_val(width), Int_val(height), String_val(title));
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

/*
value raylib_IsWindowState(value flag)
{
    bool result = IsWindowState(UNKNOWN(flag));
    return Val_bool(result);
}
*/

/*
value raylib_SetWindowState(value flags)
{
    SetWindowState(UNKNOWN(flags));
    return Val_unit;
}
*/

/*
value raylib_ClearWindowState(value flags)
{
    ClearWindowState(UNKNOWN(flags));
    return Val_unit;
}
*/

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

/*
value raylib_SetWindowIcon(value image)
{
    SetWindowIcon(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_SetWindowIcons(value images, value count)
{
    SetWindowIcons(UNKNOWN(images), Int_val(count));
    return Val_unit;
}
*/

value raylib_SetWindowTitle(value title)
{
    SetWindowTitle(String_val(title));
    return Val_unit;
}

value raylib_SetWindowPosition(value x, value y)
{
    SetWindowPosition(Int_val(x), Int_val(y));
    return Val_unit;
}

value raylib_SetWindowMonitor(value monitor)
{
    SetWindowMonitor(Int_val(monitor));
    return Val_unit;
}

value raylib_SetWindowMinSize(value width, value height)
{
    SetWindowMinSize(Int_val(width), Int_val(height));
    return Val_unit;
}

value raylib_SetWindowMaxSize(value width, value height)
{
    SetWindowMaxSize(Int_val(width), Int_val(height));
    return Val_unit;
}

value raylib_SetWindowSize(value width, value height)
{
    SetWindowSize(Int_val(width), Int_val(height));
    return Val_unit;
}

value raylib_SetWindowOpacity(value opacity)
{
    SetWindowOpacity(Double_val(opacity));
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

/*
value raylib_GetMonitorPosition(value monitor)
{
    Vector2 result = GetMonitorPosition(Int_val(monitor));
    return UNKNOWN(result);
}
*/

value raylib_GetMonitorWidth(value monitor)
{
    int result = GetMonitorWidth(Int_val(monitor));
    return Val_int(result);
}

value raylib_GetMonitorHeight(value monitor)
{
    int result = GetMonitorHeight(Int_val(monitor));
    return Val_int(result);
}

value raylib_GetMonitorPhysicalWidth(value monitor)
{
    int result = GetMonitorPhysicalWidth(Int_val(monitor));
    return Val_int(result);
}

value raylib_GetMonitorPhysicalHeight(value monitor)
{
    int result = GetMonitorPhysicalHeight(Int_val(monitor));
    return Val_int(result);
}

value raylib_GetMonitorRefreshRate(value monitor)
{
    int result = GetMonitorRefreshRate(Int_val(monitor));
    return Val_int(result);
}

/*
value raylib_GetWindowPosition(value unit)
{
    Vector2 result = GetWindowPosition();
    return UNKNOWN(result);
}
*/

/*
value raylib_GetWindowScaleDPI(value unit)
{
    Vector2 result = GetWindowScaleDPI();
    return UNKNOWN(result);
}
*/

value raylib_GetMonitorName(value monitor)
{
    const char * result = GetMonitorName(Int_val(monitor));
    return Val_string(result);
}

value raylib_SetClipboardText(value text)
{
    SetClipboardText(String_val(text));
    return Val_unit;
}

value raylib_GetClipboardText(value unit)
{
    const char * result = GetClipboardText();
    return Val_string(result);
}

/*
value raylib_GetClipboardImage(value unit)
{
    Image result = GetClipboardImage();
    return UNKNOWN(result);
}
*/

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

value raylib_ClearBackground(value color)
{
    ClearBackground(Color_val(color));
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
value raylib_BeginMode2D(value camera)
{
    BeginMode2D(UNKNOWN(camera));
    return Val_unit;
}
*/

value raylib_EndMode2D(value unit)
{
    EndMode2D();
    return Val_unit;
}

/*
value raylib_BeginMode3D(value camera)
{
    BeginMode3D(UNKNOWN(camera));
    return Val_unit;
}
*/

value raylib_EndMode3D(value unit)
{
    EndMode3D();
    return Val_unit;
}

/*
value raylib_BeginTextureMode(value target)
{
    BeginTextureMode(UNKNOWN(target));
    return Val_unit;
}
*/

value raylib_EndTextureMode(value unit)
{
    EndTextureMode();
    return Val_unit;
}

/*
value raylib_BeginShaderMode(value shader)
{
    BeginShaderMode(UNKNOWN(shader));
    return Val_unit;
}
*/

value raylib_EndShaderMode(value unit)
{
    EndShaderMode();
    return Val_unit;
}

value raylib_BeginBlendMode(value mode)
{
    BeginBlendMode(Int_val(mode));
    return Val_unit;
}

value raylib_EndBlendMode(value unit)
{
    EndBlendMode();
    return Val_unit;
}

value raylib_BeginScissorMode(value x, value y, value width, value height)
{
    BeginScissorMode(Int_val(x), Int_val(y), Int_val(width), Int_val(height));
    return Val_unit;
}

value raylib_EndScissorMode(value unit)
{
    EndScissorMode();
    return Val_unit;
}

/*
value raylib_BeginVrStereoMode(value config)
{
    BeginVrStereoMode(UNKNOWN(config));
    return Val_unit;
}
*/

value raylib_EndVrStereoMode(value unit)
{
    EndVrStereoMode();
    return Val_unit;
}

/*
value raylib_LoadVrStereoConfig(value device)
{
    VrStereoConfig result = LoadVrStereoConfig(UNKNOWN(device));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadVrStereoConfig(value config)
{
    UnloadVrStereoConfig(UNKNOWN(config));
    return Val_unit;
}
*/

/*
value raylib_LoadShader(value vsFileName, value fsFileName)
{
    Shader result = LoadShader(String_val(vsFileName), String_val(fsFileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadShaderFromMemory(value vsCode, value fsCode)
{
    Shader result = LoadShaderFromMemory(String_val(vsCode), String_val(fsCode));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsShaderValid(value shader)
{
    bool result = IsShaderValid(UNKNOWN(shader));
    return Val_bool(result);
}
*/

/*
value raylib_GetShaderLocation(value shader, value uniformName)
{
    int result = GetShaderLocation(UNKNOWN(shader), String_val(uniformName));
    return Val_int(result);
}
*/

/*
value raylib_GetShaderLocationAttrib(value shader, value attribName)
{
    int result = GetShaderLocationAttrib(UNKNOWN(shader), String_val(attribName));
    return Val_int(result);
}
*/

/*
value raylib_SetShaderValue(value shader, value locIndex, value value, value uniformType)
{
    SetShaderValue(UNKNOWN(shader), Int_val(locIndex), UNKNOWN(value), Int_val(uniformType));
    return Val_unit;
}
*/

/*
value raylib_SetShaderValueV(value shader, value locIndex, value value, value uniformType, value count)
{
    SetShaderValueV(UNKNOWN(shader), Int_val(locIndex), UNKNOWN(value), Int_val(uniformType), Int_val(count));
    return Val_unit;
}
*/

/*
value raylib_SetShaderValueMatrix(value shader, value locIndex, value mat)
{
    SetShaderValueMatrix(UNKNOWN(shader), Int_val(locIndex), UNKNOWN(mat));
    return Val_unit;
}
*/

/*
value raylib_SetShaderValueTexture(value shader, value locIndex, value texture)
{
    SetShaderValueTexture(UNKNOWN(shader), Int_val(locIndex), UNKNOWN(texture));
    return Val_unit;
}
*/

/*
value raylib_UnloadShader(value shader)
{
    UnloadShader(UNKNOWN(shader));
    return Val_unit;
}
*/

/*
value raylib_GetScreenToWorldRay(value position, value camera)
{
    Ray result = GetScreenToWorldRay(UNKNOWN(position), UNKNOWN(camera));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetScreenToWorldRayEx(value position, value camera, value width, value height)
{
    Ray result = GetScreenToWorldRayEx(UNKNOWN(position), UNKNOWN(camera), Int_val(width), Int_val(height));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetWorldToScreen(value position, value camera)
{
    Vector2 result = GetWorldToScreen(UNKNOWN(position), UNKNOWN(camera));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetWorldToScreenEx(value position, value camera, value width, value height)
{
    Vector2 result = GetWorldToScreenEx(UNKNOWN(position), UNKNOWN(camera), Int_val(width), Int_val(height));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetWorldToScreen2D(value position, value camera)
{
    Vector2 result = GetWorldToScreen2D(UNKNOWN(position), UNKNOWN(camera));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetScreenToWorld2D(value position, value camera)
{
    Vector2 result = GetScreenToWorld2D(UNKNOWN(position), UNKNOWN(camera));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetCameraMatrix(value camera)
{
    Matrix result = GetCameraMatrix(UNKNOWN(camera));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetCameraMatrix2D(value camera)
{
    Matrix result = GetCameraMatrix2D(UNKNOWN(camera));
    return UNKNOWN(result);
}
*/

value raylib_SetTargetFPS(value fps)
{
    SetTargetFPS(Int_val(fps));
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
value raylib_WaitTime(value seconds)
{
    WaitTime(UNKNOWN(seconds));
    return Val_unit;
}
*/

/*
value raylib_SetRandomSeed(value seed)
{
    SetRandomSeed(UNKNOWN(seed));
    return Val_unit;
}
*/

value raylib_GetRandomValue(value min, value max)
{
    int result = GetRandomValue(Int_val(min), Int_val(max));
    return Val_int(result);
}

/*
value raylib_LoadRandomSequence(value count, value min, value max)
{
    int * result = LoadRandomSequence(UNKNOWN(count), Int_val(min), Int_val(max));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadRandomSequence(value sequence)
{
    UnloadRandomSequence(UNKNOWN(sequence));
    return Val_unit;
}
*/

value raylib_TakeScreenshot(value fileName)
{
    TakeScreenshot(String_val(fileName));
    return Val_unit;
}

/*
value raylib_SetConfigFlags(value flags)
{
    SetConfigFlags(UNKNOWN(flags));
    return Val_unit;
}
*/

value raylib_OpenURL(value url)
{
    OpenURL(String_val(url));
    return Val_unit;
}

/*
value raylib_TraceLog(value logLevel, value text, value args)
{
    TraceLog(Int_val(logLevel), String_val(text), UNKNOWN(args));
    return Val_unit;
}
*/

value raylib_SetTraceLogLevel(value logLevel)
{
    SetTraceLogLevel(Int_val(logLevel));
    return Val_unit;
}

/*
value raylib_MemAlloc(value size)
{
    void * result = MemAlloc(UNKNOWN(size));
    return UNKNOWN(result);
}
*/

/*
value raylib_MemRealloc(value ptr, value size)
{
    void * result = MemRealloc(UNKNOWN(ptr), UNKNOWN(size));
    return UNKNOWN(result);
}
*/

/*
value raylib_MemFree(value ptr)
{
    MemFree(UNKNOWN(ptr));
    return Val_unit;
}
*/

/*
value raylib_SetTraceLogCallback(value callback)
{
    SetTraceLogCallback(UNKNOWN(callback));
    return Val_unit;
}
*/

/*
value raylib_SetLoadFileDataCallback(value callback)
{
    SetLoadFileDataCallback(UNKNOWN(callback));
    return Val_unit;
}
*/

/*
value raylib_SetSaveFileDataCallback(value callback)
{
    SetSaveFileDataCallback(UNKNOWN(callback));
    return Val_unit;
}
*/

/*
value raylib_SetLoadFileTextCallback(value callback)
{
    SetLoadFileTextCallback(UNKNOWN(callback));
    return Val_unit;
}
*/

/*
value raylib_SetSaveFileTextCallback(value callback)
{
    SetSaveFileTextCallback(UNKNOWN(callback));
    return Val_unit;
}
*/

/*
value raylib_LoadFileData(value fileName, value dataSize)
{
    unsigned char * result = LoadFileData(String_val(fileName), UNKNOWN(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadFileData(value data)
{
    UnloadFileData(UNKNOWN(data));
    return Val_unit;
}
*/

/*
value raylib_SaveFileData(value fileName, value data, value dataSize)
{
    bool result = SaveFileData(String_val(fileName), UNKNOWN(data), Int_val(dataSize));
    return Val_bool(result);
}
*/

/*
value raylib_ExportDataAsCode(value data, value dataSize, value fileName)
{
    bool result = ExportDataAsCode(UNKNOWN(data), Int_val(dataSize), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_LoadFileText(value fileName)
{
    char * result = LoadFileText(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadFileText(value text)
{
    UnloadFileText(UNKNOWN(text));
    return Val_unit;
}
*/

/*
value raylib_SaveFileText(value fileName, value text)
{
    bool result = SaveFileText(String_val(fileName), UNKNOWN(text));
    return Val_bool(result);
}
*/

value raylib_FileExists(value fileName)
{
    bool result = FileExists(String_val(fileName));
    return Val_bool(result);
}

value raylib_DirectoryExists(value dirPath)
{
    bool result = DirectoryExists(String_val(dirPath));
    return Val_bool(result);
}

value raylib_IsFileExtension(value fileName, value ext)
{
    bool result = IsFileExtension(String_val(fileName), String_val(ext));
    return Val_bool(result);
}

value raylib_GetFileLength(value fileName)
{
    int result = GetFileLength(String_val(fileName));
    return Val_int(result);
}

value raylib_GetFileExtension(value fileName)
{
    const char * result = GetFileExtension(String_val(fileName));
    return Val_string(result);
}

value raylib_GetFileName(value filePath)
{
    const char * result = GetFileName(String_val(filePath));
    return Val_string(result);
}

value raylib_GetFileNameWithoutExt(value filePath)
{
    const char * result = GetFileNameWithoutExt(String_val(filePath));
    return Val_string(result);
}

value raylib_GetDirectoryPath(value filePath)
{
    const char * result = GetDirectoryPath(String_val(filePath));
    return Val_string(result);
}

value raylib_GetPrevDirectoryPath(value dirPath)
{
    const char * result = GetPrevDirectoryPath(String_val(dirPath));
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

value raylib_MakeDirectory(value dirPath)
{
    int result = MakeDirectory(String_val(dirPath));
    return Val_int(result);
}

value raylib_ChangeDirectory(value dir)
{
    bool result = ChangeDirectory(String_val(dir));
    return Val_bool(result);
}

value raylib_IsPathFile(value path)
{
    bool result = IsPathFile(String_val(path));
    return Val_bool(result);
}

value raylib_IsFileNameValid(value fileName)
{
    bool result = IsFileNameValid(String_val(fileName));
    return Val_bool(result);
}

/*
value raylib_LoadDirectoryFiles(value dirPath)
{
    FilePathList result = LoadDirectoryFiles(String_val(dirPath));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadDirectoryFilesEx(value basePath, value filter, value scanSubdirs)
{
    FilePathList result = LoadDirectoryFilesEx(String_val(basePath), String_val(filter), Bool_val(scanSubdirs));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadDirectoryFiles(value files)
{
    UnloadDirectoryFiles(UNKNOWN(files));
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
value raylib_UnloadDroppedFiles(value files)
{
    UnloadDroppedFiles(UNKNOWN(files));
    return Val_unit;
}
*/

/*
value raylib_GetFileModTime(value fileName)
{
    long result = GetFileModTime(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_CompressData(value data, value dataSize, value compDataSize)
{
    unsigned char * result = CompressData(UNKNOWN(data), Int_val(dataSize), UNKNOWN(compDataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_DecompressData(value compData, value compDataSize, value dataSize)
{
    unsigned char * result = DecompressData(UNKNOWN(compData), Int_val(compDataSize), UNKNOWN(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_EncodeDataBase64(value data, value dataSize, value outputSize)
{
    char * result = EncodeDataBase64(UNKNOWN(data), Int_val(dataSize), UNKNOWN(outputSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_DecodeDataBase64(value data, value outputSize)
{
    unsigned char * result = DecodeDataBase64(UNKNOWN(data), UNKNOWN(outputSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_ComputeCRC32(value data, value dataSize)
{
    unsigned int result = ComputeCRC32(UNKNOWN(data), Int_val(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_ComputeMD5(value data, value dataSize)
{
    unsigned int * result = ComputeMD5(UNKNOWN(data), Int_val(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_ComputeSHA1(value data, value dataSize)
{
    unsigned int * result = ComputeSHA1(UNKNOWN(data), Int_val(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadAutomationEventList(value fileName)
{
    AutomationEventList result = LoadAutomationEventList(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadAutomationEventList(value list)
{
    UnloadAutomationEventList(UNKNOWN(list));
    return Val_unit;
}
*/

/*
value raylib_ExportAutomationEventList(value list, value fileName)
{
    bool result = ExportAutomationEventList(UNKNOWN(list), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_SetAutomationEventList(value list)
{
    SetAutomationEventList(UNKNOWN(list));
    return Val_unit;
}
*/

value raylib_SetAutomationEventBaseFrame(value frame)
{
    SetAutomationEventBaseFrame(Int_val(frame));
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
value raylib_PlayAutomationEvent(value event)
{
    PlayAutomationEvent(UNKNOWN(event));
    return Val_unit;
}
*/

value raylib_IsKeyPressed(value key)
{
    bool result = IsKeyPressed(Int_val(key));
    return Val_bool(result);
}

value raylib_IsKeyPressedRepeat(value key)
{
    bool result = IsKeyPressedRepeat(Int_val(key));
    return Val_bool(result);
}

value raylib_IsKeyDown(value key)
{
    bool result = IsKeyDown(Int_val(key));
    return Val_bool(result);
}

value raylib_IsKeyReleased(value key)
{
    bool result = IsKeyReleased(Int_val(key));
    return Val_bool(result);
}

value raylib_IsKeyUp(value key)
{
    bool result = IsKeyUp(Int_val(key));
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

value raylib_SetExitKey(value key)
{
    SetExitKey(Int_val(key));
    return Val_unit;
}

value raylib_IsGamepadAvailable(value gamepad)
{
    bool result = IsGamepadAvailable(Int_val(gamepad));
    return Val_bool(result);
}

value raylib_GetGamepadName(value gamepad)
{
    const char * result = GetGamepadName(Int_val(gamepad));
    return Val_string(result);
}

value raylib_IsGamepadButtonPressed(value gamepad, value button)
{
    bool result = IsGamepadButtonPressed(Int_val(gamepad), Int_val(button));
    return Val_bool(result);
}

value raylib_IsGamepadButtonDown(value gamepad, value button)
{
    bool result = IsGamepadButtonDown(Int_val(gamepad), Int_val(button));
    return Val_bool(result);
}

value raylib_IsGamepadButtonReleased(value gamepad, value button)
{
    bool result = IsGamepadButtonReleased(Int_val(gamepad), Int_val(button));
    return Val_bool(result);
}

value raylib_IsGamepadButtonUp(value gamepad, value button)
{
    bool result = IsGamepadButtonUp(Int_val(gamepad), Int_val(button));
    return Val_bool(result);
}

value raylib_GetGamepadButtonPressed(value unit)
{
    int result = GetGamepadButtonPressed();
    return Val_int(result);
}

value raylib_GetGamepadAxisCount(value gamepad)
{
    int result = GetGamepadAxisCount(Int_val(gamepad));
    return Val_int(result);
}

value raylib_GetGamepadAxisMovement(value gamepad, value axis)
{
    float result = GetGamepadAxisMovement(Int_val(gamepad), Int_val(axis));
    return copy_double(result);
}

value raylib_SetGamepadMappings(value mappings)
{
    int result = SetGamepadMappings(String_val(mappings));
    return Val_int(result);
}

value raylib_SetGamepadVibration(value gamepad, value leftMotor, value rightMotor, value duration)
{
    SetGamepadVibration(Int_val(gamepad), Double_val(leftMotor), Double_val(rightMotor), Double_val(duration));
    return Val_unit;
}

value raylib_IsMouseButtonPressed(value button)
{
    bool result = IsMouseButtonPressed(Int_val(button));
    return Val_bool(result);
}

value raylib_IsMouseButtonDown(value button)
{
    bool result = IsMouseButtonDown(Int_val(button));
    return Val_bool(result);
}

value raylib_IsMouseButtonReleased(value button)
{
    bool result = IsMouseButtonReleased(Int_val(button));
    return Val_bool(result);
}

value raylib_IsMouseButtonUp(value button)
{
    bool result = IsMouseButtonUp(Int_val(button));
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

/*
value raylib_GetMousePosition(value unit)
{
    Vector2 result = GetMousePosition();
    return UNKNOWN(result);
}
*/

/*
value raylib_GetMouseDelta(value unit)
{
    Vector2 result = GetMouseDelta();
    return UNKNOWN(result);
}
*/

value raylib_SetMousePosition(value x, value y)
{
    SetMousePosition(Int_val(x), Int_val(y));
    return Val_unit;
}

value raylib_SetMouseOffset(value offsetX, value offsetY)
{
    SetMouseOffset(Int_val(offsetX), Int_val(offsetY));
    return Val_unit;
}

value raylib_SetMouseScale(value scaleX, value scaleY)
{
    SetMouseScale(Double_val(scaleX), Double_val(scaleY));
    return Val_unit;
}

value raylib_GetMouseWheelMove(value unit)
{
    float result = GetMouseWheelMove();
    return copy_double(result);
}

/*
value raylib_GetMouseWheelMoveV(value unit)
{
    Vector2 result = GetMouseWheelMoveV();
    return UNKNOWN(result);
}
*/

value raylib_SetMouseCursor(value cursor)
{
    SetMouseCursor(Int_val(cursor));
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

/*
value raylib_GetTouchPosition(value index)
{
    Vector2 result = GetTouchPosition(Int_val(index));
    return UNKNOWN(result);
}
*/

value raylib_GetTouchPointId(value index)
{
    int result = GetTouchPointId(Int_val(index));
    return Val_int(result);
}

value raylib_GetTouchPointCount(value unit)
{
    int result = GetTouchPointCount();
    return Val_int(result);
}

/*
value raylib_SetGesturesEnabled(value flags)
{
    SetGesturesEnabled(UNKNOWN(flags));
    return Val_unit;
}
*/

/*
value raylib_IsGestureDetected(value gesture)
{
    bool result = IsGestureDetected(UNKNOWN(gesture));
    return Val_bool(result);
}
*/

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

/*
value raylib_GetGestureDragVector(value unit)
{
    Vector2 result = GetGestureDragVector();
    return UNKNOWN(result);
}
*/

value raylib_GetGestureDragAngle(value unit)
{
    float result = GetGestureDragAngle();
    return copy_double(result);
}

/*
value raylib_GetGesturePinchVector(value unit)
{
    Vector2 result = GetGesturePinchVector();
    return UNKNOWN(result);
}
*/

value raylib_GetGesturePinchAngle(value unit)
{
    float result = GetGesturePinchAngle();
    return copy_double(result);
}

/*
value raylib_UpdateCamera(value camera, value mode)
{
    UpdateCamera(UNKNOWN(camera), Int_val(mode));
    return Val_unit;
}
*/

/*
value raylib_UpdateCameraPro(value camera, value movement, value rotation, value zoom)
{
    UpdateCameraPro(UNKNOWN(camera), UNKNOWN(movement), UNKNOWN(rotation), Double_val(zoom));
    return Val_unit;
}
*/

/*
value raylib_SetShapesTexture(value texture, value source)
{
    SetShapesTexture(UNKNOWN(texture), UNKNOWN(source));
    return Val_unit;
}
*/

/*
value raylib_GetShapesTexture(value unit)
{
    Texture2D result = GetShapesTexture();
    return UNKNOWN(result);
}
*/

/*
value raylib_GetShapesTextureRectangle(value unit)
{
    Rectangle result = GetShapesTextureRectangle();
    return UNKNOWN(result);
}
*/

value raylib_DrawPixel(value posX, value posY, value color)
{
    DrawPixel(Int_val(posX), Int_val(posY), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawPixelV(value position, value color)
{
    DrawPixelV(UNKNOWN(position), Color_val(color));
    return Val_unit;
}
*/

value raylib_DrawLine(value startPosX, value startPosY, value endPosX, value endPosY, value color)
{
    DrawLine(Int_val(startPosX), Int_val(startPosY), Int_val(endPosX), Int_val(endPosY), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawLineV(value startPos, value endPos, value color)
{
    DrawLineV(UNKNOWN(startPos), UNKNOWN(endPos), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawLineEx(value startPos, value endPos, value thick, value color)
{
    DrawLineEx(UNKNOWN(startPos), UNKNOWN(endPos), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawLineStrip(value points, value pointCount, value color)
{
    DrawLineStrip(UNKNOWN(points), Int_val(pointCount), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawLineBezier(value startPos, value endPos, value thick, value color)
{
    DrawLineBezier(UNKNOWN(startPos), UNKNOWN(endPos), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

value raylib_DrawCircle(value centerX, value centerY, value radius, value color)
{
    DrawCircle(Int_val(centerX), Int_val(centerY), Double_val(radius), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawCircleSector(value center, value radius, value startAngle, value endAngle, value segments, value color)
{
    DrawCircleSector(UNKNOWN(center), Double_val(radius), Double_val(startAngle), Double_val(endAngle), Int_val(segments), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCircleSectorLines(value center, value radius, value startAngle, value endAngle, value segments, value color)
{
    DrawCircleSectorLines(UNKNOWN(center), Double_val(radius), Double_val(startAngle), Double_val(endAngle), Int_val(segments), Color_val(color));
    return Val_unit;
}
*/

value raylib_DrawCircleGradient(value centerX, value centerY, value radius, value inner, value outer)
{
    DrawCircleGradient(Int_val(centerX), Int_val(centerY), Double_val(radius), Color_val(inner), Color_val(outer));
    return Val_unit;
}

/*
value raylib_DrawCircleV(value center, value radius, value color)
{
    DrawCircleV(UNKNOWN(center), Double_val(radius), Color_val(color));
    return Val_unit;
}
*/

value raylib_DrawCircleLines(value centerX, value centerY, value radius, value color)
{
    DrawCircleLines(Int_val(centerX), Int_val(centerY), Double_val(radius), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawCircleLinesV(value center, value radius, value color)
{
    DrawCircleLinesV(UNKNOWN(center), Double_val(radius), Color_val(color));
    return Val_unit;
}
*/

value raylib_DrawEllipse(value centerX, value centerY, value radiusH, value radiusV, value color)
{
    DrawEllipse(Int_val(centerX), Int_val(centerY), Double_val(radiusH), Double_val(radiusV), Color_val(color));
    return Val_unit;
}

value raylib_DrawEllipseLines(value centerX, value centerY, value radiusH, value radiusV, value color)
{
    DrawEllipseLines(Int_val(centerX), Int_val(centerY), Double_val(radiusH), Double_val(radiusV), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawRing(value center, value innerRadius, value outerRadius, value startAngle, value endAngle, value segments, value color)
{
    DrawRing(UNKNOWN(center), Double_val(innerRadius), Double_val(outerRadius), Double_val(startAngle), Double_val(endAngle), Int_val(segments), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRingLines(value center, value innerRadius, value outerRadius, value startAngle, value endAngle, value segments, value color)
{
    DrawRingLines(UNKNOWN(center), Double_val(innerRadius), Double_val(outerRadius), Double_val(startAngle), Double_val(endAngle), Int_val(segments), Color_val(color));
    return Val_unit;
}
*/

value raylib_DrawRectangle(value posX, value posY, value width, value height, value color)
{
    DrawRectangle(Int_val(posX), Int_val(posY), Int_val(width), Int_val(height), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawRectangleV(value position, value size, value color)
{
    DrawRectangleV(UNKNOWN(position), UNKNOWN(size), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRectangleRec(value rec, value color)
{
    DrawRectangleRec(UNKNOWN(rec), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRectanglePro(value rec, value origin, value rotation, value color)
{
    DrawRectanglePro(UNKNOWN(rec), UNKNOWN(origin), Double_val(rotation), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRectangleGradientV(value posX, value posY, value width, value height, value top, value bottom)
{
    DrawRectangleGradientV(Int_val(posX), Int_val(posY), Int_val(width), Int_val(height), Color_val(top), Color_val(bottom));
    return Val_unit;
}
*/

/*
value raylib_DrawRectangleGradientH(value posX, value posY, value width, value height, value left, value right)
{
    DrawRectangleGradientH(Int_val(posX), Int_val(posY), Int_val(width), Int_val(height), Color_val(left), Color_val(right));
    return Val_unit;
}
*/

/*
value raylib_DrawRectangleGradientEx(value rec, value topLeft, value bottomLeft, value topRight, value bottomRight)
{
    DrawRectangleGradientEx(UNKNOWN(rec), Color_val(topLeft), Color_val(bottomLeft), Color_val(topRight), Color_val(bottomRight));
    return Val_unit;
}
*/

value raylib_DrawRectangleLines(value posX, value posY, value width, value height, value color)
{
    DrawRectangleLines(Int_val(posX), Int_val(posY), Int_val(width), Int_val(height), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawRectangleLinesEx(value rec, value lineThick, value color)
{
    DrawRectangleLinesEx(UNKNOWN(rec), Double_val(lineThick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRectangleRounded(value rec, value roundness, value segments, value color)
{
    DrawRectangleRounded(UNKNOWN(rec), Double_val(roundness), Int_val(segments), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRectangleRoundedLines(value rec, value roundness, value segments, value color)
{
    DrawRectangleRoundedLines(UNKNOWN(rec), Double_val(roundness), Int_val(segments), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRectangleRoundedLinesEx(value rec, value roundness, value segments, value lineThick, value color)
{
    DrawRectangleRoundedLinesEx(UNKNOWN(rec), Double_val(roundness), Int_val(segments), Double_val(lineThick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawTriangle(value v1, value v2, value v3, value color)
{
    DrawTriangle(UNKNOWN(v1), UNKNOWN(v2), UNKNOWN(v3), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawTriangleLines(value v1, value v2, value v3, value color)
{
    DrawTriangleLines(UNKNOWN(v1), UNKNOWN(v2), UNKNOWN(v3), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawTriangleFan(value points, value pointCount, value color)
{
    DrawTriangleFan(UNKNOWN(points), Int_val(pointCount), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawTriangleStrip(value points, value pointCount, value color)
{
    DrawTriangleStrip(UNKNOWN(points), Int_val(pointCount), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawPoly(value center, value sides, value radius, value rotation, value color)
{
    DrawPoly(UNKNOWN(center), Int_val(sides), Double_val(radius), Double_val(rotation), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawPolyLines(value center, value sides, value radius, value rotation, value color)
{
    DrawPolyLines(UNKNOWN(center), Int_val(sides), Double_val(radius), Double_val(rotation), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawPolyLinesEx(value center, value sides, value radius, value rotation, value lineThick, value color)
{
    DrawPolyLinesEx(UNKNOWN(center), Int_val(sides), Double_val(radius), Double_val(rotation), Double_val(lineThick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineLinear(value points, value pointCount, value thick, value color)
{
    DrawSplineLinear(UNKNOWN(points), Int_val(pointCount), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineBasis(value points, value pointCount, value thick, value color)
{
    DrawSplineBasis(UNKNOWN(points), Int_val(pointCount), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineCatmullRom(value points, value pointCount, value thick, value color)
{
    DrawSplineCatmullRom(UNKNOWN(points), Int_val(pointCount), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineBezierQuadratic(value points, value pointCount, value thick, value color)
{
    DrawSplineBezierQuadratic(UNKNOWN(points), Int_val(pointCount), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineBezierCubic(value points, value pointCount, value thick, value color)
{
    DrawSplineBezierCubic(UNKNOWN(points), Int_val(pointCount), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineSegmentLinear(value p1, value p2, value thick, value color)
{
    DrawSplineSegmentLinear(UNKNOWN(p1), UNKNOWN(p2), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineSegmentBasis(value p1, value p2, value p3, value p4, value thick, value color)
{
    DrawSplineSegmentBasis(UNKNOWN(p1), UNKNOWN(p2), UNKNOWN(p3), UNKNOWN(p4), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineSegmentCatmullRom(value p1, value p2, value p3, value p4, value thick, value color)
{
    DrawSplineSegmentCatmullRom(UNKNOWN(p1), UNKNOWN(p2), UNKNOWN(p3), UNKNOWN(p4), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineSegmentBezierQuadratic(value p1, value c2, value p3, value thick, value color)
{
    DrawSplineSegmentBezierQuadratic(UNKNOWN(p1), UNKNOWN(c2), UNKNOWN(p3), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSplineSegmentBezierCubic(value p1, value c2, value c3, value p4, value thick, value color)
{
    DrawSplineSegmentBezierCubic(UNKNOWN(p1), UNKNOWN(c2), UNKNOWN(c3), UNKNOWN(p4), Double_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_GetSplinePointLinear(value startPos, value endPos, value t)
{
    Vector2 result = GetSplinePointLinear(UNKNOWN(startPos), UNKNOWN(endPos), Double_val(t));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetSplinePointBasis(value p1, value p2, value p3, value p4, value t)
{
    Vector2 result = GetSplinePointBasis(UNKNOWN(p1), UNKNOWN(p2), UNKNOWN(p3), UNKNOWN(p4), Double_val(t));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetSplinePointCatmullRom(value p1, value p2, value p3, value p4, value t)
{
    Vector2 result = GetSplinePointCatmullRom(UNKNOWN(p1), UNKNOWN(p2), UNKNOWN(p3), UNKNOWN(p4), Double_val(t));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetSplinePointBezierQuad(value p1, value c2, value p3, value t)
{
    Vector2 result = GetSplinePointBezierQuad(UNKNOWN(p1), UNKNOWN(c2), UNKNOWN(p3), Double_val(t));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetSplinePointBezierCubic(value p1, value c2, value c3, value p4, value t)
{
    Vector2 result = GetSplinePointBezierCubic(UNKNOWN(p1), UNKNOWN(c2), UNKNOWN(c3), UNKNOWN(p4), Double_val(t));
    return UNKNOWN(result);
}
*/

/*
value raylib_CheckCollisionRecs(value rec1, value rec2)
{
    bool result = CheckCollisionRecs(UNKNOWN(rec1), UNKNOWN(rec2));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionCircles(value center1, value radius1, value center2, value radius2)
{
    bool result = CheckCollisionCircles(UNKNOWN(center1), Double_val(radius1), UNKNOWN(center2), Double_val(radius2));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionCircleRec(value center, value radius, value rec)
{
    bool result = CheckCollisionCircleRec(UNKNOWN(center), Double_val(radius), UNKNOWN(rec));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionCircleLine(value center, value radius, value p1, value p2)
{
    bool result = CheckCollisionCircleLine(UNKNOWN(center), Double_val(radius), UNKNOWN(p1), UNKNOWN(p2));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionPointRec(value point, value rec)
{
    bool result = CheckCollisionPointRec(UNKNOWN(point), UNKNOWN(rec));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionPointCircle(value point, value center, value radius)
{
    bool result = CheckCollisionPointCircle(UNKNOWN(point), UNKNOWN(center), Double_val(radius));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionPointTriangle(value point, value p1, value p2, value p3)
{
    bool result = CheckCollisionPointTriangle(UNKNOWN(point), UNKNOWN(p1), UNKNOWN(p2), UNKNOWN(p3));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionPointLine(value point, value p1, value p2, value threshold)
{
    bool result = CheckCollisionPointLine(UNKNOWN(point), UNKNOWN(p1), UNKNOWN(p2), Int_val(threshold));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionPointPoly(value point, value points, value pointCount)
{
    bool result = CheckCollisionPointPoly(UNKNOWN(point), UNKNOWN(points), Int_val(pointCount));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionLines(value startPos1, value endPos1, value startPos2, value endPos2, value collisionPoint)
{
    bool result = CheckCollisionLines(UNKNOWN(startPos1), UNKNOWN(endPos1), UNKNOWN(startPos2), UNKNOWN(endPos2), UNKNOWN(collisionPoint));
    return Val_bool(result);
}
*/

/*
value raylib_GetCollisionRec(value rec1, value rec2)
{
    Rectangle result = GetCollisionRec(UNKNOWN(rec1), UNKNOWN(rec2));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImage(value fileName)
{
    Image result = LoadImage(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImageRaw(value fileName, value width, value height, value format, value headerSize)
{
    Image result = LoadImageRaw(String_val(fileName), Int_val(width), Int_val(height), Int_val(format), Int_val(headerSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImageAnim(value fileName, value frames)
{
    Image result = LoadImageAnim(String_val(fileName), UNKNOWN(frames));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImageAnimFromMemory(value fileType, value fileData, value dataSize, value frames)
{
    Image result = LoadImageAnimFromMemory(String_val(fileType), UNKNOWN(fileData), Int_val(dataSize), UNKNOWN(frames));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImageFromMemory(value fileType, value fileData, value dataSize)
{
    Image result = LoadImageFromMemory(String_val(fileType), UNKNOWN(fileData), Int_val(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImageFromTexture(value texture)
{
    Image result = LoadImageFromTexture(UNKNOWN(texture));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImageFromScreen(value unit)
{
    Image result = LoadImageFromScreen();
    return UNKNOWN(result);
}
*/

/*
value raylib_IsImageValid(value image)
{
    bool result = IsImageValid(UNKNOWN(image));
    return Val_bool(result);
}
*/

/*
value raylib_UnloadImage(value image)
{
    UnloadImage(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ExportImage(value image, value fileName)
{
    bool result = ExportImage(UNKNOWN(image), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_ExportImageToMemory(value image, value fileType, value fileSize)
{
    unsigned char * result = ExportImageToMemory(UNKNOWN(image), String_val(fileType), UNKNOWN(fileSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_ExportImageAsCode(value image, value fileName)
{
    bool result = ExportImageAsCode(UNKNOWN(image), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_GenImageColor(value width, value height, value color)
{
    Image result = GenImageColor(Int_val(width), Int_val(height), Color_val(color));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageGradientLinear(value width, value height, value direction, value start, value end)
{
    Image result = GenImageGradientLinear(Int_val(width), Int_val(height), Int_val(direction), Color_val(start), Color_val(end));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageGradientRadial(value width, value height, value density, value inner, value outer)
{
    Image result = GenImageGradientRadial(Int_val(width), Int_val(height), Double_val(density), Color_val(inner), Color_val(outer));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageGradientSquare(value width, value height, value density, value inner, value outer)
{
    Image result = GenImageGradientSquare(Int_val(width), Int_val(height), Double_val(density), Color_val(inner), Color_val(outer));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageChecked(value width, value height, value checksX, value checksY, value col1, value col2)
{
    Image result = GenImageChecked(Int_val(width), Int_val(height), Int_val(checksX), Int_val(checksY), Color_val(col1), Color_val(col2));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageWhiteNoise(value width, value height, value factor)
{
    Image result = GenImageWhiteNoise(Int_val(width), Int_val(height), Double_val(factor));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImagePerlinNoise(value width, value height, value offsetX, value offsetY, value scale)
{
    Image result = GenImagePerlinNoise(Int_val(width), Int_val(height), Int_val(offsetX), Int_val(offsetY), Double_val(scale));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageCellular(value width, value height, value tileSize)
{
    Image result = GenImageCellular(Int_val(width), Int_val(height), Int_val(tileSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageText(value width, value height, value text)
{
    Image result = GenImageText(Int_val(width), Int_val(height), String_val(text));
    return UNKNOWN(result);
}
*/

/*
value raylib_ImageCopy(value image)
{
    Image result = ImageCopy(UNKNOWN(image));
    return UNKNOWN(result);
}
*/

/*
value raylib_ImageFromImage(value image, value rec)
{
    Image result = ImageFromImage(UNKNOWN(image), UNKNOWN(rec));
    return UNKNOWN(result);
}
*/

/*
value raylib_ImageFromChannel(value image, value selectedChannel)
{
    Image result = ImageFromChannel(UNKNOWN(image), Int_val(selectedChannel));
    return UNKNOWN(result);
}
*/

/*
value raylib_ImageText(value text, value fontSize, value color)
{
    Image result = ImageText(String_val(text), Int_val(fontSize), Color_val(color));
    return UNKNOWN(result);
}
*/

/*
value raylib_ImageTextEx(value font, value text, value fontSize, value spacing, value tint)
{
    Image result = ImageTextEx(UNKNOWN(font), String_val(text), Double_val(fontSize), Double_val(spacing), Color_val(tint));
    return UNKNOWN(result);
}
*/

/*
value raylib_ImageFormat(value image, value newFormat)
{
    ImageFormat(UNKNOWN(image), Int_val(newFormat));
    return Val_unit;
}
*/

/*
value raylib_ImageToPOT(value image, value fill)
{
    ImageToPOT(UNKNOWN(image), Color_val(fill));
    return Val_unit;
}
*/

/*
value raylib_ImageCrop(value image, value crop)
{
    ImageCrop(UNKNOWN(image), UNKNOWN(crop));
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaCrop(value image, value threshold)
{
    ImageAlphaCrop(UNKNOWN(image), Double_val(threshold));
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaClear(value image, value color, value threshold)
{
    ImageAlphaClear(UNKNOWN(image), Color_val(color), Double_val(threshold));
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaMask(value image, value alphaMask)
{
    ImageAlphaMask(UNKNOWN(image), UNKNOWN(alphaMask));
    return Val_unit;
}
*/

/*
value raylib_ImageAlphaPremultiply(value image)
{
    ImageAlphaPremultiply(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageBlurGaussian(value image, value blurSize)
{
    ImageBlurGaussian(UNKNOWN(image), Int_val(blurSize));
    return Val_unit;
}
*/

/*
value raylib_ImageKernelConvolution(value image, value kernel, value kernelSize)
{
    ImageKernelConvolution(UNKNOWN(image), UNKNOWN(kernel), Int_val(kernelSize));
    return Val_unit;
}
*/

/*
value raylib_ImageResize(value image, value newWidth, value newHeight)
{
    ImageResize(UNKNOWN(image), Int_val(newWidth), Int_val(newHeight));
    return Val_unit;
}
*/

/*
value raylib_ImageResizeNN(value image, value newWidth, value newHeight)
{
    ImageResizeNN(UNKNOWN(image), Int_val(newWidth), Int_val(newHeight));
    return Val_unit;
}
*/

/*
value raylib_ImageResizeCanvas(value image, value newWidth, value newHeight, value offsetX, value offsetY, value fill)
{
    ImageResizeCanvas(UNKNOWN(image), Int_val(newWidth), Int_val(newHeight), Int_val(offsetX), Int_val(offsetY), Color_val(fill));
    return Val_unit;
}
*/

/*
value raylib_ImageMipmaps(value image)
{
    ImageMipmaps(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageDither(value image, value rBpp, value gBpp, value bBpp, value aBpp)
{
    ImageDither(UNKNOWN(image), Int_val(rBpp), Int_val(gBpp), Int_val(bBpp), Int_val(aBpp));
    return Val_unit;
}
*/

/*
value raylib_ImageFlipVertical(value image)
{
    ImageFlipVertical(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageFlipHorizontal(value image)
{
    ImageFlipHorizontal(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageRotate(value image, value degrees)
{
    ImageRotate(UNKNOWN(image), Int_val(degrees));
    return Val_unit;
}
*/

/*
value raylib_ImageRotateCW(value image)
{
    ImageRotateCW(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageRotateCCW(value image)
{
    ImageRotateCCW(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageColorTint(value image, value color)
{
    ImageColorTint(UNKNOWN(image), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageColorInvert(value image)
{
    ImageColorInvert(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageColorGrayscale(value image)
{
    ImageColorGrayscale(UNKNOWN(image));
    return Val_unit;
}
*/

/*
value raylib_ImageColorContrast(value image, value contrast)
{
    ImageColorContrast(UNKNOWN(image), Double_val(contrast));
    return Val_unit;
}
*/

/*
value raylib_ImageColorBrightness(value image, value brightness)
{
    ImageColorBrightness(UNKNOWN(image), Int_val(brightness));
    return Val_unit;
}
*/

/*
value raylib_ImageColorReplace(value image, value color, value replace)
{
    ImageColorReplace(UNKNOWN(image), Color_val(color), Color_val(replace));
    return Val_unit;
}
*/

/*
value raylib_LoadImageColors(value image)
{
    Color * result = LoadImageColors(UNKNOWN(image));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadImagePalette(value image, value maxPaletteSize, value colorCount)
{
    Color * result = LoadImagePalette(UNKNOWN(image), Int_val(maxPaletteSize), UNKNOWN(colorCount));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadImageColors(value colors)
{
    UnloadImageColors(UNKNOWN(colors));
    return Val_unit;
}
*/

/*
value raylib_UnloadImagePalette(value colors)
{
    UnloadImagePalette(UNKNOWN(colors));
    return Val_unit;
}
*/

/*
value raylib_GetImageAlphaBorder(value image, value threshold)
{
    Rectangle result = GetImageAlphaBorder(UNKNOWN(image), Double_val(threshold));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetImageColor(value image, value x, value y)
{
    Color result = GetImageColor(UNKNOWN(image), Int_val(x), Int_val(y));
    return Val_color(result);
}
*/

/*
value raylib_ImageClearBackground(value dst, value color)
{
    ImageClearBackground(UNKNOWN(dst), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawPixel(value dst, value posX, value posY, value color)
{
    ImageDrawPixel(UNKNOWN(dst), Int_val(posX), Int_val(posY), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawPixelV(value dst, value position, value color)
{
    ImageDrawPixelV(UNKNOWN(dst), UNKNOWN(position), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawLine(value dst, value startPosX, value startPosY, value endPosX, value endPosY, value color)
{
    ImageDrawLine(UNKNOWN(dst), Int_val(startPosX), Int_val(startPosY), Int_val(endPosX), Int_val(endPosY), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawLineV(value dst, value start, value end, value color)
{
    ImageDrawLineV(UNKNOWN(dst), UNKNOWN(start), UNKNOWN(end), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawLineEx(value dst, value start, value end, value thick, value color)
{
    ImageDrawLineEx(UNKNOWN(dst), UNKNOWN(start), UNKNOWN(end), Int_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircle(value dst, value centerX, value centerY, value radius, value color)
{
    ImageDrawCircle(UNKNOWN(dst), Int_val(centerX), Int_val(centerY), Int_val(radius), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircleV(value dst, value center, value radius, value color)
{
    ImageDrawCircleV(UNKNOWN(dst), UNKNOWN(center), Int_val(radius), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircleLines(value dst, value centerX, value centerY, value radius, value color)
{
    ImageDrawCircleLines(UNKNOWN(dst), Int_val(centerX), Int_val(centerY), Int_val(radius), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawCircleLinesV(value dst, value center, value radius, value color)
{
    ImageDrawCircleLinesV(UNKNOWN(dst), UNKNOWN(center), Int_val(radius), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangle(value dst, value posX, value posY, value width, value height, value color)
{
    ImageDrawRectangle(UNKNOWN(dst), Int_val(posX), Int_val(posY), Int_val(width), Int_val(height), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangleV(value dst, value position, value size, value color)
{
    ImageDrawRectangleV(UNKNOWN(dst), UNKNOWN(position), UNKNOWN(size), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangleRec(value dst, value rec, value color)
{
    ImageDrawRectangleRec(UNKNOWN(dst), UNKNOWN(rec), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawRectangleLines(value dst, value rec, value thick, value color)
{
    ImageDrawRectangleLines(UNKNOWN(dst), UNKNOWN(rec), Int_val(thick), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangle(value dst, value v1, value v2, value v3, value color)
{
    ImageDrawTriangle(UNKNOWN(dst), UNKNOWN(v1), UNKNOWN(v2), UNKNOWN(v3), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleEx(value dst, value v1, value v2, value v3, value c1, value c2, value c3)
{
    ImageDrawTriangleEx(UNKNOWN(dst), UNKNOWN(v1), UNKNOWN(v2), UNKNOWN(v3), Color_val(c1), Color_val(c2), Color_val(c3));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleLines(value dst, value v1, value v2, value v3, value color)
{
    ImageDrawTriangleLines(UNKNOWN(dst), UNKNOWN(v1), UNKNOWN(v2), UNKNOWN(v3), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleFan(value dst, value points, value pointCount, value color)
{
    ImageDrawTriangleFan(UNKNOWN(dst), UNKNOWN(points), Int_val(pointCount), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTriangleStrip(value dst, value points, value pointCount, value color)
{
    ImageDrawTriangleStrip(UNKNOWN(dst), UNKNOWN(points), Int_val(pointCount), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDraw(value dst, value src, value srcRec, value dstRec, value tint)
{
    ImageDraw(UNKNOWN(dst), UNKNOWN(src), UNKNOWN(srcRec), UNKNOWN(dstRec), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawText(value dst, value text, value posX, value posY, value fontSize, value color)
{
    ImageDrawText(UNKNOWN(dst), String_val(text), Int_val(posX), Int_val(posY), Int_val(fontSize), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_ImageDrawTextEx(value dst, value font, value text, value position, value fontSize, value spacing, value tint)
{
    ImageDrawTextEx(UNKNOWN(dst), UNKNOWN(font), String_val(text), UNKNOWN(position), Double_val(fontSize), Double_val(spacing), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_LoadTexture(value fileName)
{
    Texture2D result = LoadTexture(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadTextureFromImage(value image)
{
    Texture2D result = LoadTextureFromImage(UNKNOWN(image));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadTextureCubemap(value image, value layout)
{
    TextureCubemap result = LoadTextureCubemap(UNKNOWN(image), Int_val(layout));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadRenderTexture(value width, value height)
{
    RenderTexture2D result = LoadRenderTexture(Int_val(width), Int_val(height));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsTextureValid(value texture)
{
    bool result = IsTextureValid(UNKNOWN(texture));
    return Val_bool(result);
}
*/

/*
value raylib_UnloadTexture(value texture)
{
    UnloadTexture(UNKNOWN(texture));
    return Val_unit;
}
*/

/*
value raylib_IsRenderTextureValid(value target)
{
    bool result = IsRenderTextureValid(UNKNOWN(target));
    return Val_bool(result);
}
*/

/*
value raylib_UnloadRenderTexture(value target)
{
    UnloadRenderTexture(UNKNOWN(target));
    return Val_unit;
}
*/

/*
value raylib_UpdateTexture(value texture, value pixels)
{
    UpdateTexture(UNKNOWN(texture), UNKNOWN(pixels));
    return Val_unit;
}
*/

/*
value raylib_UpdateTextureRec(value texture, value rec, value pixels)
{
    UpdateTextureRec(UNKNOWN(texture), UNKNOWN(rec), UNKNOWN(pixels));
    return Val_unit;
}
*/

/*
value raylib_GenTextureMipmaps(value texture)
{
    GenTextureMipmaps(UNKNOWN(texture));
    return Val_unit;
}
*/

/*
value raylib_SetTextureFilter(value texture, value filter)
{
    SetTextureFilter(UNKNOWN(texture), Int_val(filter));
    return Val_unit;
}
*/

/*
value raylib_SetTextureWrap(value texture, value wrap)
{
    SetTextureWrap(UNKNOWN(texture), Int_val(wrap));
    return Val_unit;
}
*/

/*
value raylib_DrawTexture(value texture, value posX, value posY, value tint)
{
    DrawTexture(UNKNOWN(texture), Int_val(posX), Int_val(posY), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTextureV(value texture, value position, value tint)
{
    DrawTextureV(UNKNOWN(texture), UNKNOWN(position), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTextureEx(value texture, value position, value rotation, value scale, value tint)
{
    DrawTextureEx(UNKNOWN(texture), UNKNOWN(position), Double_val(rotation), Double_val(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTextureRec(value texture, value source, value position, value tint)
{
    DrawTextureRec(UNKNOWN(texture), UNKNOWN(source), UNKNOWN(position), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTexturePro(value texture, value source, value dest, value origin, value rotation, value tint)
{
    DrawTexturePro(UNKNOWN(texture), UNKNOWN(source), UNKNOWN(dest), UNKNOWN(origin), Double_val(rotation), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTextureNPatch(value texture, value nPatchInfo, value dest, value origin, value rotation, value tint)
{
    DrawTextureNPatch(UNKNOWN(texture), UNKNOWN(nPatchInfo), UNKNOWN(dest), UNKNOWN(origin), Double_val(rotation), Color_val(tint));
    return Val_unit;
}
*/

value raylib_ColorIsEqual(value col1, value col2)
{
    bool result = ColorIsEqual(Color_val(col1), Color_val(col2));
    return Val_bool(result);
}

value raylib_Fade(value color, value alpha)
{
    Color result = Fade(Color_val(color), Double_val(alpha));
    return Val_color(result);
}

value raylib_ColorToInt(value color)
{
    int result = ColorToInt(Color_val(color));
    return Val_int(result);
}

/*
value raylib_ColorNormalize(value color)
{
    Vector4 result = ColorNormalize(Color_val(color));
    return UNKNOWN(result);
}
*/

/*
value raylib_ColorFromNormalized(value normalized)
{
    Color result = ColorFromNormalized(UNKNOWN(normalized));
    return Val_color(result);
}
*/

/*
value raylib_ColorToHSV(value color)
{
    Vector3 result = ColorToHSV(Color_val(color));
    return UNKNOWN(result);
}
*/

value raylib_ColorFromHSV(value hue, value saturation, value value)
{
    Color result = ColorFromHSV(Double_val(hue), Double_val(saturation), Double_val(value));
    return Val_color(result);
}

value raylib_ColorTint(value color, value tint)
{
    Color result = ColorTint(Color_val(color), Color_val(tint));
    return Val_color(result);
}

value raylib_ColorBrightness(value color, value factor)
{
    Color result = ColorBrightness(Color_val(color), Double_val(factor));
    return Val_color(result);
}

value raylib_ColorContrast(value color, value contrast)
{
    Color result = ColorContrast(Color_val(color), Double_val(contrast));
    return Val_color(result);
}

value raylib_ColorAlpha(value color, value alpha)
{
    Color result = ColorAlpha(Color_val(color), Double_val(alpha));
    return Val_color(result);
}

value raylib_ColorAlphaBlend(value dst, value src, value tint)
{
    Color result = ColorAlphaBlend(Color_val(dst), Color_val(src), Color_val(tint));
    return Val_color(result);
}

value raylib_ColorLerp(value color1, value color2, value factor)
{
    Color result = ColorLerp(Color_val(color1), Color_val(color2), Double_val(factor));
    return Val_color(result);
}

/*
value raylib_GetColor(value hexValue)
{
    Color result = GetColor(UNKNOWN(hexValue));
    return Val_color(result);
}
*/

/*
value raylib_GetPixelColor(value srcPtr, value format)
{
    Color result = GetPixelColor(UNKNOWN(srcPtr), Int_val(format));
    return Val_color(result);
}
*/

/*
value raylib_SetPixelColor(value dstPtr, value color, value format)
{
    SetPixelColor(UNKNOWN(dstPtr), Color_val(color), Int_val(format));
    return Val_unit;
}
*/

value raylib_GetPixelDataSize(value width, value height, value format)
{
    int result = GetPixelDataSize(Int_val(width), Int_val(height), Int_val(format));
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
value raylib_LoadFont(value fileName)
{
    Font result = LoadFont(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadFontEx(value fileName, value fontSize, value codepoints, value codepointCount)
{
    Font result = LoadFontEx(String_val(fileName), Int_val(fontSize), UNKNOWN(codepoints), Int_val(codepointCount));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadFontFromImage(value image, value key, value firstChar)
{
    Font result = LoadFontFromImage(UNKNOWN(image), Color_val(key), Int_val(firstChar));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadFontFromMemory(value fileType, value fileData, value dataSize, value fontSize, value codepoints, value codepointCount)
{
    Font result = LoadFontFromMemory(String_val(fileType), UNKNOWN(fileData), Int_val(dataSize), Int_val(fontSize), UNKNOWN(codepoints), Int_val(codepointCount));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsFontValid(value font)
{
    bool result = IsFontValid(UNKNOWN(font));
    return Val_bool(result);
}
*/

/*
value raylib_LoadFontData(value fileData, value dataSize, value fontSize, value codepoints, value codepointCount, value type)
{
    GlyphInfo * result = LoadFontData(UNKNOWN(fileData), Int_val(dataSize), Int_val(fontSize), UNKNOWN(codepoints), Int_val(codepointCount), Int_val(type));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenImageFontAtlas(value glyphs, value glyphRecs, value glyphCount, value fontSize, value padding, value packMethod)
{
    Image result = GenImageFontAtlas(UNKNOWN(glyphs), UNKNOWN(glyphRecs), Int_val(glyphCount), Int_val(fontSize), Int_val(padding), Int_val(packMethod));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadFontData(value glyphs, value glyphCount)
{
    UnloadFontData(UNKNOWN(glyphs), Int_val(glyphCount));
    return Val_unit;
}
*/

/*
value raylib_UnloadFont(value font)
{
    UnloadFont(UNKNOWN(font));
    return Val_unit;
}
*/

/*
value raylib_ExportFontAsCode(value font, value fileName)
{
    bool result = ExportFontAsCode(UNKNOWN(font), String_val(fileName));
    return Val_bool(result);
}
*/

value raylib_DrawFPS(value posX, value posY)
{
    DrawFPS(Int_val(posX), Int_val(posY));
    return Val_unit;
}

value raylib_DrawText(value text, value posX, value posY, value fontSize, value color)
{
    DrawText(String_val(text), Int_val(posX), Int_val(posY), Int_val(fontSize), Color_val(color));
    return Val_unit;
}

/*
value raylib_DrawTextEx(value font, value text, value position, value fontSize, value spacing, value tint)
{
    DrawTextEx(UNKNOWN(font), String_val(text), UNKNOWN(position), Double_val(fontSize), Double_val(spacing), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTextPro(value font, value text, value position, value origin, value rotation, value fontSize, value spacing, value tint)
{
    DrawTextPro(UNKNOWN(font), String_val(text), UNKNOWN(position), UNKNOWN(origin), Double_val(rotation), Double_val(fontSize), Double_val(spacing), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTextCodepoint(value font, value codepoint, value position, value fontSize, value tint)
{
    DrawTextCodepoint(UNKNOWN(font), Int_val(codepoint), UNKNOWN(position), Double_val(fontSize), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawTextCodepoints(value font, value codepoints, value codepointCount, value position, value fontSize, value spacing, value tint)
{
    DrawTextCodepoints(UNKNOWN(font), UNKNOWN(codepoints), Int_val(codepointCount), UNKNOWN(position), Double_val(fontSize), Double_val(spacing), Color_val(tint));
    return Val_unit;
}
*/

value raylib_SetTextLineSpacing(value spacing)
{
    SetTextLineSpacing(Int_val(spacing));
    return Val_unit;
}

value raylib_MeasureText(value text, value fontSize)
{
    int result = MeasureText(String_val(text), Int_val(fontSize));
    return Val_int(result);
}

/*
value raylib_MeasureTextEx(value font, value text, value fontSize, value spacing)
{
    Vector2 result = MeasureTextEx(UNKNOWN(font), String_val(text), Double_val(fontSize), Double_val(spacing));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetGlyphIndex(value font, value codepoint)
{
    int result = GetGlyphIndex(UNKNOWN(font), Int_val(codepoint));
    return Val_int(result);
}
*/

/*
value raylib_GetGlyphInfo(value font, value codepoint)
{
    GlyphInfo result = GetGlyphInfo(UNKNOWN(font), Int_val(codepoint));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetGlyphAtlasRec(value font, value codepoint)
{
    Rectangle result = GetGlyphAtlasRec(UNKNOWN(font), Int_val(codepoint));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadUTF8(value codepoints, value length)
{
    char * result = LoadUTF8(UNKNOWN(codepoints), Int_val(length));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadUTF8(value text)
{
    UnloadUTF8(UNKNOWN(text));
    return Val_unit;
}
*/

/*
value raylib_LoadCodepoints(value text, value count)
{
    int * result = LoadCodepoints(String_val(text), UNKNOWN(count));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadCodepoints(value codepoints)
{
    UnloadCodepoints(UNKNOWN(codepoints));
    return Val_unit;
}
*/

value raylib_GetCodepointCount(value text)
{
    int result = GetCodepointCount(String_val(text));
    return Val_int(result);
}

/*
value raylib_GetCodepoint(value text, value codepointSize)
{
    int result = GetCodepoint(String_val(text), UNKNOWN(codepointSize));
    return Val_int(result);
}
*/

/*
value raylib_GetCodepointNext(value text, value codepointSize)
{
    int result = GetCodepointNext(String_val(text), UNKNOWN(codepointSize));
    return Val_int(result);
}
*/

/*
value raylib_GetCodepointPrevious(value text, value codepointSize)
{
    int result = GetCodepointPrevious(String_val(text), UNKNOWN(codepointSize));
    return Val_int(result);
}
*/

/*
value raylib_CodepointToUTF8(value codepoint, value utf8Size)
{
    const char * result = CodepointToUTF8(Int_val(codepoint), UNKNOWN(utf8Size));
    return Val_string(result);
}
*/

/*
value raylib_TextCopy(value dst, value src)
{
    int result = TextCopy(UNKNOWN(dst), String_val(src));
    return Val_int(result);
}
*/

value raylib_TextIsEqual(value text1, value text2)
{
    bool result = TextIsEqual(String_val(text1), String_val(text2));
    return Val_bool(result);
}

/*
value raylib_TextLength(value text)
{
    unsigned int result = TextLength(String_val(text));
    return UNKNOWN(result);
}
*/

/*
value raylib_TextFormat(value text, value args)
{
    const char * result = TextFormat(String_val(text), UNKNOWN(args));
    return Val_string(result);
}
*/

value raylib_TextSubtext(value text, value position, value length)
{
    const char * result = TextSubtext(String_val(text), Int_val(position), Int_val(length));
    return Val_string(result);
}

/*
value raylib_TextReplace(value text, value replace, value by)
{
    char * result = TextReplace(String_val(text), String_val(replace), String_val(by));
    return UNKNOWN(result);
}
*/

/*
value raylib_TextInsert(value text, value insert, value position)
{
    char * result = TextInsert(String_val(text), String_val(insert), Int_val(position));
    return UNKNOWN(result);
}
*/

/*
value raylib_TextJoin(value textList, value count, value delimiter)
{
    const char * result = TextJoin(UNKNOWN(textList), Int_val(count), String_val(delimiter));
    return Val_string(result);
}
*/

/*
value raylib_TextSplit(value text, value delimiter, value count)
{
    const char ** result = TextSplit(String_val(text), UNKNOWN(delimiter), UNKNOWN(count));
    return UNKNOWN(result);
}
*/

/*
value raylib_TextAppend(value text, value append, value position)
{
    TextAppend(UNKNOWN(text), String_val(append), UNKNOWN(position));
    return Val_unit;
}
*/

value raylib_TextFindIndex(value text, value find)
{
    int result = TextFindIndex(String_val(text), String_val(find));
    return Val_int(result);
}

value raylib_TextToUpper(value text)
{
    const char * result = TextToUpper(String_val(text));
    return Val_string(result);
}

value raylib_TextToLower(value text)
{
    const char * result = TextToLower(String_val(text));
    return Val_string(result);
}

value raylib_TextToPascal(value text)
{
    const char * result = TextToPascal(String_val(text));
    return Val_string(result);
}

value raylib_TextToSnake(value text)
{
    const char * result = TextToSnake(String_val(text));
    return Val_string(result);
}

value raylib_TextToCamel(value text)
{
    const char * result = TextToCamel(String_val(text));
    return Val_string(result);
}

value raylib_TextToInteger(value text)
{
    int result = TextToInteger(String_val(text));
    return Val_int(result);
}

value raylib_TextToFloat(value text)
{
    float result = TextToFloat(String_val(text));
    return copy_double(result);
}

/*
value raylib_DrawLine3D(value startPos, value endPos, value color)
{
    DrawLine3D(UNKNOWN(startPos), UNKNOWN(endPos), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawPoint3D(value position, value color)
{
    DrawPoint3D(UNKNOWN(position), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCircle3D(value center, value radius, value rotationAxis, value rotationAngle, value color)
{
    DrawCircle3D(UNKNOWN(center), Double_val(radius), UNKNOWN(rotationAxis), Double_val(rotationAngle), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawTriangle3D(value v1, value v2, value v3, value color)
{
    DrawTriangle3D(UNKNOWN(v1), UNKNOWN(v2), UNKNOWN(v3), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawTriangleStrip3D(value points, value pointCount, value color)
{
    DrawTriangleStrip3D(UNKNOWN(points), Int_val(pointCount), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCube(value position, value width, value height, value length, value color)
{
    DrawCube(UNKNOWN(position), Double_val(width), Double_val(height), Double_val(length), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCubeV(value position, value size, value color)
{
    DrawCubeV(UNKNOWN(position), UNKNOWN(size), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCubeWires(value position, value width, value height, value length, value color)
{
    DrawCubeWires(UNKNOWN(position), Double_val(width), Double_val(height), Double_val(length), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCubeWiresV(value position, value size, value color)
{
    DrawCubeWiresV(UNKNOWN(position), UNKNOWN(size), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSphere(value centerPos, value radius, value color)
{
    DrawSphere(UNKNOWN(centerPos), Double_val(radius), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSphereEx(value centerPos, value radius, value rings, value slices, value color)
{
    DrawSphereEx(UNKNOWN(centerPos), Double_val(radius), Int_val(rings), Int_val(slices), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawSphereWires(value centerPos, value radius, value rings, value slices, value color)
{
    DrawSphereWires(UNKNOWN(centerPos), Double_val(radius), Int_val(rings), Int_val(slices), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCylinder(value position, value radiusTop, value radiusBottom, value height, value slices, value color)
{
    DrawCylinder(UNKNOWN(position), Double_val(radiusTop), Double_val(radiusBottom), Double_val(height), Int_val(slices), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCylinderEx(value startPos, value endPos, value startRadius, value endRadius, value sides, value color)
{
    DrawCylinderEx(UNKNOWN(startPos), UNKNOWN(endPos), Double_val(startRadius), Double_val(endRadius), Int_val(sides), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCylinderWires(value position, value radiusTop, value radiusBottom, value height, value slices, value color)
{
    DrawCylinderWires(UNKNOWN(position), Double_val(radiusTop), Double_val(radiusBottom), Double_val(height), Int_val(slices), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCylinderWiresEx(value startPos, value endPos, value startRadius, value endRadius, value sides, value color)
{
    DrawCylinderWiresEx(UNKNOWN(startPos), UNKNOWN(endPos), Double_val(startRadius), Double_val(endRadius), Int_val(sides), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCapsule(value startPos, value endPos, value radius, value slices, value rings, value color)
{
    DrawCapsule(UNKNOWN(startPos), UNKNOWN(endPos), Double_val(radius), Int_val(slices), Int_val(rings), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawCapsuleWires(value startPos, value endPos, value radius, value slices, value rings, value color)
{
    DrawCapsuleWires(UNKNOWN(startPos), UNKNOWN(endPos), Double_val(radius), Int_val(slices), Int_val(rings), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawPlane(value centerPos, value size, value color)
{
    DrawPlane(UNKNOWN(centerPos), UNKNOWN(size), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawRay(value ray, value color)
{
    DrawRay(UNKNOWN(ray), Color_val(color));
    return Val_unit;
}
*/

value raylib_DrawGrid(value slices, value spacing)
{
    DrawGrid(Int_val(slices), Double_val(spacing));
    return Val_unit;
}

/*
value raylib_LoadModel(value fileName)
{
    Model result = LoadModel(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadModelFromMesh(value mesh)
{
    Model result = LoadModelFromMesh(UNKNOWN(mesh));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsModelValid(value model)
{
    bool result = IsModelValid(UNKNOWN(model));
    return Val_bool(result);
}
*/

/*
value raylib_UnloadModel(value model)
{
    UnloadModel(UNKNOWN(model));
    return Val_unit;
}
*/

/*
value raylib_GetModelBoundingBox(value model)
{
    BoundingBox result = GetModelBoundingBox(UNKNOWN(model));
    return UNKNOWN(result);
}
*/

/*
value raylib_DrawModel(value model, value position, value scale, value tint)
{
    DrawModel(UNKNOWN(model), UNKNOWN(position), Double_val(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawModelEx(value model, value position, value rotationAxis, value rotationAngle, value scale, value tint)
{
    DrawModelEx(UNKNOWN(model), UNKNOWN(position), UNKNOWN(rotationAxis), Double_val(rotationAngle), UNKNOWN(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawModelWires(value model, value position, value scale, value tint)
{
    DrawModelWires(UNKNOWN(model), UNKNOWN(position), Double_val(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawModelWiresEx(value model, value position, value rotationAxis, value rotationAngle, value scale, value tint)
{
    DrawModelWiresEx(UNKNOWN(model), UNKNOWN(position), UNKNOWN(rotationAxis), Double_val(rotationAngle), UNKNOWN(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawModelPoints(value model, value position, value scale, value tint)
{
    DrawModelPoints(UNKNOWN(model), UNKNOWN(position), Double_val(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawModelPointsEx(value model, value position, value rotationAxis, value rotationAngle, value scale, value tint)
{
    DrawModelPointsEx(UNKNOWN(model), UNKNOWN(position), UNKNOWN(rotationAxis), Double_val(rotationAngle), UNKNOWN(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawBoundingBox(value box, value color)
{
    DrawBoundingBox(UNKNOWN(box), Color_val(color));
    return Val_unit;
}
*/

/*
value raylib_DrawBillboard(value camera, value texture, value position, value scale, value tint)
{
    DrawBillboard(UNKNOWN(camera), UNKNOWN(texture), UNKNOWN(position), Double_val(scale), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawBillboardRec(value camera, value texture, value source, value position, value size, value tint)
{
    DrawBillboardRec(UNKNOWN(camera), UNKNOWN(texture), UNKNOWN(source), UNKNOWN(position), UNKNOWN(size), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_DrawBillboardPro(value camera, value texture, value source, value position, value up, value size, value origin, value rotation, value tint)
{
    DrawBillboardPro(UNKNOWN(camera), UNKNOWN(texture), UNKNOWN(source), UNKNOWN(position), UNKNOWN(up), UNKNOWN(size), UNKNOWN(origin), Double_val(rotation), Color_val(tint));
    return Val_unit;
}
*/

/*
value raylib_UploadMesh(value mesh, value dynamic)
{
    UploadMesh(UNKNOWN(mesh), Bool_val(dynamic));
    return Val_unit;
}
*/

/*
value raylib_UpdateMeshBuffer(value mesh, value index, value data, value dataSize, value offset)
{
    UpdateMeshBuffer(UNKNOWN(mesh), Int_val(index), UNKNOWN(data), Int_val(dataSize), Int_val(offset));
    return Val_unit;
}
*/

/*
value raylib_UnloadMesh(value mesh)
{
    UnloadMesh(UNKNOWN(mesh));
    return Val_unit;
}
*/

/*
value raylib_DrawMesh(value mesh, value material, value transform)
{
    DrawMesh(UNKNOWN(mesh), UNKNOWN(material), UNKNOWN(transform));
    return Val_unit;
}
*/

/*
value raylib_DrawMeshInstanced(value mesh, value material, value transforms, value instances)
{
    DrawMeshInstanced(UNKNOWN(mesh), UNKNOWN(material), UNKNOWN(transforms), Int_val(instances));
    return Val_unit;
}
*/

/*
value raylib_GetMeshBoundingBox(value mesh)
{
    BoundingBox result = GetMeshBoundingBox(UNKNOWN(mesh));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshTangents(value mesh)
{
    GenMeshTangents(UNKNOWN(mesh));
    return Val_unit;
}
*/

/*
value raylib_ExportMesh(value mesh, value fileName)
{
    bool result = ExportMesh(UNKNOWN(mesh), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_ExportMeshAsCode(value mesh, value fileName)
{
    bool result = ExportMeshAsCode(UNKNOWN(mesh), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_GenMeshPoly(value sides, value radius)
{
    Mesh result = GenMeshPoly(Int_val(sides), Double_val(radius));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshPlane(value width, value length, value resX, value resZ)
{
    Mesh result = GenMeshPlane(Double_val(width), Double_val(length), Int_val(resX), Int_val(resZ));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCube(value width, value height, value length)
{
    Mesh result = GenMeshCube(Double_val(width), Double_val(height), Double_val(length));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshSphere(value radius, value rings, value slices)
{
    Mesh result = GenMeshSphere(Double_val(radius), Int_val(rings), Int_val(slices));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshHemiSphere(value radius, value rings, value slices)
{
    Mesh result = GenMeshHemiSphere(Double_val(radius), Int_val(rings), Int_val(slices));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCylinder(value radius, value height, value slices)
{
    Mesh result = GenMeshCylinder(Double_val(radius), Double_val(height), Int_val(slices));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCone(value radius, value height, value slices)
{
    Mesh result = GenMeshCone(Double_val(radius), Double_val(height), Int_val(slices));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshTorus(value radius, value size, value radSeg, value sides)
{
    Mesh result = GenMeshTorus(Double_val(radius), Double_val(size), Int_val(radSeg), Int_val(sides));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshKnot(value radius, value size, value radSeg, value sides)
{
    Mesh result = GenMeshKnot(Double_val(radius), Double_val(size), Int_val(radSeg), Int_val(sides));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshHeightmap(value heightmap, value size)
{
    Mesh result = GenMeshHeightmap(UNKNOWN(heightmap), UNKNOWN(size));
    return UNKNOWN(result);
}
*/

/*
value raylib_GenMeshCubicmap(value cubicmap, value cubeSize)
{
    Mesh result = GenMeshCubicmap(UNKNOWN(cubicmap), UNKNOWN(cubeSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadMaterials(value fileName, value materialCount)
{
    Material * result = LoadMaterials(String_val(fileName), UNKNOWN(materialCount));
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
value raylib_IsMaterialValid(value material)
{
    bool result = IsMaterialValid(UNKNOWN(material));
    return Val_bool(result);
}
*/

/*
value raylib_UnloadMaterial(value material)
{
    UnloadMaterial(UNKNOWN(material));
    return Val_unit;
}
*/

/*
value raylib_SetMaterialTexture(value material, value mapType, value texture)
{
    SetMaterialTexture(UNKNOWN(material), Int_val(mapType), UNKNOWN(texture));
    return Val_unit;
}
*/

/*
value raylib_SetModelMeshMaterial(value model, value meshId, value materialId)
{
    SetModelMeshMaterial(UNKNOWN(model), Int_val(meshId), Int_val(materialId));
    return Val_unit;
}
*/

/*
value raylib_LoadModelAnimations(value fileName, value animCount)
{
    ModelAnimation * result = LoadModelAnimations(String_val(fileName), UNKNOWN(animCount));
    return UNKNOWN(result);
}
*/

/*
value raylib_UpdateModelAnimation(value model, value anim, value frame)
{
    UpdateModelAnimation(UNKNOWN(model), UNKNOWN(anim), Int_val(frame));
    return Val_unit;
}
*/

/*
value raylib_UpdateModelAnimationBones(value model, value anim, value frame)
{
    UpdateModelAnimationBones(UNKNOWN(model), UNKNOWN(anim), Int_val(frame));
    return Val_unit;
}
*/

/*
value raylib_UnloadModelAnimation(value anim)
{
    UnloadModelAnimation(UNKNOWN(anim));
    return Val_unit;
}
*/

/*
value raylib_UnloadModelAnimations(value animations, value animCount)
{
    UnloadModelAnimations(UNKNOWN(animations), Int_val(animCount));
    return Val_unit;
}
*/

/*
value raylib_IsModelAnimationValid(value model, value anim)
{
    bool result = IsModelAnimationValid(UNKNOWN(model), UNKNOWN(anim));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionSpheres(value center1, value radius1, value center2, value radius2)
{
    bool result = CheckCollisionSpheres(UNKNOWN(center1), Double_val(radius1), UNKNOWN(center2), Double_val(radius2));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionBoxes(value box1, value box2)
{
    bool result = CheckCollisionBoxes(UNKNOWN(box1), UNKNOWN(box2));
    return Val_bool(result);
}
*/

/*
value raylib_CheckCollisionBoxSphere(value box, value center, value radius)
{
    bool result = CheckCollisionBoxSphere(UNKNOWN(box), UNKNOWN(center), Double_val(radius));
    return Val_bool(result);
}
*/

/*
value raylib_GetRayCollisionSphere(value ray, value center, value radius)
{
    RayCollision result = GetRayCollisionSphere(UNKNOWN(ray), UNKNOWN(center), Double_val(radius));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionBox(value ray, value box)
{
    RayCollision result = GetRayCollisionBox(UNKNOWN(ray), UNKNOWN(box));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionMesh(value ray, value mesh, value transform)
{
    RayCollision result = GetRayCollisionMesh(UNKNOWN(ray), UNKNOWN(mesh), UNKNOWN(transform));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionTriangle(value ray, value p1, value p2, value p3)
{
    RayCollision result = GetRayCollisionTriangle(UNKNOWN(ray), UNKNOWN(p1), UNKNOWN(p2), UNKNOWN(p3));
    return UNKNOWN(result);
}
*/

/*
value raylib_GetRayCollisionQuad(value ray, value p1, value p2, value p3, value p4)
{
    RayCollision result = GetRayCollisionQuad(UNKNOWN(ray), UNKNOWN(p1), UNKNOWN(p2), UNKNOWN(p3), UNKNOWN(p4));
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

value raylib_SetMasterVolume(value volume)
{
    SetMasterVolume(Double_val(volume));
    return Val_unit;
}

value raylib_GetMasterVolume(value unit)
{
    float result = GetMasterVolume();
    return copy_double(result);
}

/*
value raylib_LoadWave(value fileName)
{
    Wave result = LoadWave(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadWaveFromMemory(value fileType, value fileData, value dataSize)
{
    Wave result = LoadWaveFromMemory(String_val(fileType), UNKNOWN(fileData), Int_val(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsWaveValid(value wave)
{
    bool result = IsWaveValid(UNKNOWN(wave));
    return Val_bool(result);
}
*/

/*
value raylib_LoadSound(value fileName)
{
    Sound result = LoadSound(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadSoundFromWave(value wave)
{
    Sound result = LoadSoundFromWave(UNKNOWN(wave));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadSoundAlias(value source)
{
    Sound result = LoadSoundAlias(UNKNOWN(source));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsSoundValid(value sound)
{
    bool result = IsSoundValid(UNKNOWN(sound));
    return Val_bool(result);
}
*/

/*
value raylib_UpdateSound(value sound, value data, value sampleCount)
{
    UpdateSound(UNKNOWN(sound), UNKNOWN(data), Int_val(sampleCount));
    return Val_unit;
}
*/

/*
value raylib_UnloadWave(value wave)
{
    UnloadWave(UNKNOWN(wave));
    return Val_unit;
}
*/

/*
value raylib_UnloadSound(value sound)
{
    UnloadSound(UNKNOWN(sound));
    return Val_unit;
}
*/

/*
value raylib_UnloadSoundAlias(value alias)
{
    UnloadSoundAlias(UNKNOWN(alias));
    return Val_unit;
}
*/

/*
value raylib_ExportWave(value wave, value fileName)
{
    bool result = ExportWave(UNKNOWN(wave), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_ExportWaveAsCode(value wave, value fileName)
{
    bool result = ExportWaveAsCode(UNKNOWN(wave), String_val(fileName));
    return Val_bool(result);
}
*/

/*
value raylib_PlaySound(value sound)
{
    PlaySound(UNKNOWN(sound));
    return Val_unit;
}
*/

/*
value raylib_StopSound(value sound)
{
    StopSound(UNKNOWN(sound));
    return Val_unit;
}
*/

/*
value raylib_PauseSound(value sound)
{
    PauseSound(UNKNOWN(sound));
    return Val_unit;
}
*/

/*
value raylib_ResumeSound(value sound)
{
    ResumeSound(UNKNOWN(sound));
    return Val_unit;
}
*/

/*
value raylib_IsSoundPlaying(value sound)
{
    bool result = IsSoundPlaying(UNKNOWN(sound));
    return Val_bool(result);
}
*/

/*
value raylib_SetSoundVolume(value sound, value volume)
{
    SetSoundVolume(UNKNOWN(sound), Double_val(volume));
    return Val_unit;
}
*/

/*
value raylib_SetSoundPitch(value sound, value pitch)
{
    SetSoundPitch(UNKNOWN(sound), Double_val(pitch));
    return Val_unit;
}
*/

/*
value raylib_SetSoundPan(value sound, value pan)
{
    SetSoundPan(UNKNOWN(sound), Double_val(pan));
    return Val_unit;
}
*/

/*
value raylib_WaveCopy(value wave)
{
    Wave result = WaveCopy(UNKNOWN(wave));
    return UNKNOWN(result);
}
*/

/*
value raylib_WaveCrop(value wave, value initFrame, value finalFrame)
{
    WaveCrop(UNKNOWN(wave), Int_val(initFrame), Int_val(finalFrame));
    return Val_unit;
}
*/

/*
value raylib_WaveFormat(value wave, value sampleRate, value sampleSize, value channels)
{
    WaveFormat(UNKNOWN(wave), Int_val(sampleRate), Int_val(sampleSize), Int_val(channels));
    return Val_unit;
}
*/

/*
value raylib_LoadWaveSamples(value wave)
{
    float * result = LoadWaveSamples(UNKNOWN(wave));
    return UNKNOWN(result);
}
*/

/*
value raylib_UnloadWaveSamples(value samples)
{
    UnloadWaveSamples(UNKNOWN(samples));
    return Val_unit;
}
*/

/*
value raylib_LoadMusicStream(value fileName)
{
    Music result = LoadMusicStream(String_val(fileName));
    return UNKNOWN(result);
}
*/

/*
value raylib_LoadMusicStreamFromMemory(value fileType, value data, value dataSize)
{
    Music result = LoadMusicStreamFromMemory(String_val(fileType), UNKNOWN(data), Int_val(dataSize));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsMusicValid(value music)
{
    bool result = IsMusicValid(UNKNOWN(music));
    return Val_bool(result);
}
*/

/*
value raylib_UnloadMusicStream(value music)
{
    UnloadMusicStream(UNKNOWN(music));
    return Val_unit;
}
*/

/*
value raylib_PlayMusicStream(value music)
{
    PlayMusicStream(UNKNOWN(music));
    return Val_unit;
}
*/

/*
value raylib_IsMusicStreamPlaying(value music)
{
    bool result = IsMusicStreamPlaying(UNKNOWN(music));
    return Val_bool(result);
}
*/

/*
value raylib_UpdateMusicStream(value music)
{
    UpdateMusicStream(UNKNOWN(music));
    return Val_unit;
}
*/

/*
value raylib_StopMusicStream(value music)
{
    StopMusicStream(UNKNOWN(music));
    return Val_unit;
}
*/

/*
value raylib_PauseMusicStream(value music)
{
    PauseMusicStream(UNKNOWN(music));
    return Val_unit;
}
*/

/*
value raylib_ResumeMusicStream(value music)
{
    ResumeMusicStream(UNKNOWN(music));
    return Val_unit;
}
*/

/*
value raylib_SeekMusicStream(value music, value position)
{
    SeekMusicStream(UNKNOWN(music), Double_val(position));
    return Val_unit;
}
*/

/*
value raylib_SetMusicVolume(value music, value volume)
{
    SetMusicVolume(UNKNOWN(music), Double_val(volume));
    return Val_unit;
}
*/

/*
value raylib_SetMusicPitch(value music, value pitch)
{
    SetMusicPitch(UNKNOWN(music), Double_val(pitch));
    return Val_unit;
}
*/

/*
value raylib_SetMusicPan(value music, value pan)
{
    SetMusicPan(UNKNOWN(music), Double_val(pan));
    return Val_unit;
}
*/

/*
value raylib_GetMusicTimeLength(value music)
{
    float result = GetMusicTimeLength(UNKNOWN(music));
    return copy_double(result);
}
*/

/*
value raylib_GetMusicTimePlayed(value music)
{
    float result = GetMusicTimePlayed(UNKNOWN(music));
    return copy_double(result);
}
*/

/*
value raylib_LoadAudioStream(value sampleRate, value sampleSize, value channels)
{
    AudioStream result = LoadAudioStream(UNKNOWN(sampleRate), UNKNOWN(sampleSize), UNKNOWN(channels));
    return UNKNOWN(result);
}
*/

/*
value raylib_IsAudioStreamValid(value stream)
{
    bool result = IsAudioStreamValid(UNKNOWN(stream));
    return Val_bool(result);
}
*/

/*
value raylib_UnloadAudioStream(value stream)
{
    UnloadAudioStream(UNKNOWN(stream));
    return Val_unit;
}
*/

/*
value raylib_UpdateAudioStream(value stream, value data, value frameCount)
{
    UpdateAudioStream(UNKNOWN(stream), UNKNOWN(data), Int_val(frameCount));
    return Val_unit;
}
*/

/*
value raylib_IsAudioStreamProcessed(value stream)
{
    bool result = IsAudioStreamProcessed(UNKNOWN(stream));
    return Val_bool(result);
}
*/

/*
value raylib_PlayAudioStream(value stream)
{
    PlayAudioStream(UNKNOWN(stream));
    return Val_unit;
}
*/

/*
value raylib_PauseAudioStream(value stream)
{
    PauseAudioStream(UNKNOWN(stream));
    return Val_unit;
}
*/

/*
value raylib_ResumeAudioStream(value stream)
{
    ResumeAudioStream(UNKNOWN(stream));
    return Val_unit;
}
*/

/*
value raylib_IsAudioStreamPlaying(value stream)
{
    bool result = IsAudioStreamPlaying(UNKNOWN(stream));
    return Val_bool(result);
}
*/

/*
value raylib_StopAudioStream(value stream)
{
    StopAudioStream(UNKNOWN(stream));
    return Val_unit;
}
*/

/*
value raylib_SetAudioStreamVolume(value stream, value volume)
{
    SetAudioStreamVolume(UNKNOWN(stream), Double_val(volume));
    return Val_unit;
}
*/

/*
value raylib_SetAudioStreamPitch(value stream, value pitch)
{
    SetAudioStreamPitch(UNKNOWN(stream), Double_val(pitch));
    return Val_unit;
}
*/

/*
value raylib_SetAudioStreamPan(value stream, value pan)
{
    SetAudioStreamPan(UNKNOWN(stream), Double_val(pan));
    return Val_unit;
}
*/

value raylib_SetAudioStreamBufferSizeDefault(value size)
{
    SetAudioStreamBufferSizeDefault(Int_val(size));
    return Val_unit;
}

/*
value raylib_SetAudioStreamCallback(value stream, value callback)
{
    SetAudioStreamCallback(UNKNOWN(stream), UNKNOWN(callback));
    return Val_unit;
}
*/

/*
value raylib_AttachAudioStreamProcessor(value stream, value processor)
{
    AttachAudioStreamProcessor(UNKNOWN(stream), UNKNOWN(processor));
    return Val_unit;
}
*/

/*
value raylib_DetachAudioStreamProcessor(value stream, value processor)
{
    DetachAudioStreamProcessor(UNKNOWN(stream), UNKNOWN(processor));
    return Val_unit;
}
*/

/*
value raylib_AttachAudioMixedProcessor(value processor)
{
    AttachAudioMixedProcessor(UNKNOWN(processor));
    return Val_unit;
}
*/

/*
value raylib_DetachAudioMixedProcessor(value processor)
{
    DetachAudioMixedProcessor(UNKNOWN(processor));
    return Val_unit;
}
*/

