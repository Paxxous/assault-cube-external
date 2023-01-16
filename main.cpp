#include <Windows.h>
#include <iostream>

void memChange() {
  DWORD health = 2147483647;

  // 4294967293 is the max health

  std::cout << "Attaching. to window...\n";

  // Grab the window
  HWND ac_win = FindWindow(NULL, L"AssaultCube");
  if (!ac_win) { // Err checking :D
    std::cout << "Err: coudln't find assault cube window! You can access a download via:\nhttps://github.com/assaultcube/AC/releases/tag/v1.3.0.2\n";
    return;
  }

  // Get window process id
  DWORD process_id = 0;
  GetWindowThreadProcessId(ac_win, &process_id);

  // Get process handle
  HANDLE ac_process = OpenProcess(PROCESS_ALL_ACCESS, true, process_id);

  std::cout << "Bubbling up from static variable...\n";
  DWORD poin1 = 0; // What we'll jump through until we reach the entity class
  DWORD bytes_read = 0;
  ReadProcessMemory(ac_process, (void*)0x58B0B8, &poin1, 4, &bytes_read); // Poin1
  ReadProcessMemory(ac_process, (void*)poin1, &poin1, 4, &bytes_read); // Poin2
  
  //poin1 += 0x408; // Offset (health)
  std::cout << "Writing memory\n";
  // Change/write to health address
  // blah D024620
  DWORD bytes_written = 0;
  WriteProcessMemory(ac_process, (void*)(poin1 + 0x408 /* Health offset */), &health, 4, &bytes_written);


  std::cout << "Done! :D\n";
}

int main() {
  memChange();
  std::cin.get();

  return 0;
}