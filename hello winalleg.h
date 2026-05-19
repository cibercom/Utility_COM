#include <allegro.h>
#include <winalleg.h> // Must be included after allegro.h and before other Win32 headers

int main() {
    // Initialize the Allegro library
    if (allegro_init() != 0) {
        return 1;
    }

    // Call a Windows API function (e.g., MessageBox)
    MessageBox(NULL, "Hello from Win32 and Allegro!", "Windows Specifics", MB_OK);

    allegro_message("Allegro initialized successfully!");
    
    return 0;
}
END_OF_MAIN()
