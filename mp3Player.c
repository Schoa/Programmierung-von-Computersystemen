#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a song
typedef struct Song {
    char title[100];
    char artist[100];
    struct Song* next;
} Song;

// Function to create a new song node
Song* createSong(const char* title, const char* artist) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (!newSong) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = NULL;
    return newSong;
}

// Function to add a song to the playlist
void addSong(Song** head, const char* title, const char* artist) {
    Song* newSong = createSong(title, artist);
    if (*head == NULL) {
        *head = newSong;
    } else {
        Song* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
}

// Function to display the playlist
void displayPlaylist(Song* head) {
    if (head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }
    Song* temp = head;
    printf("Playlist:\n");
    while (temp != NULL) {
        printf("Title: %s, Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

// Function to play songs in the playlist
void playSongs(Song* head) {
    if (head == NULL) {
        printf("The playlist is empty. Nothing to play.\n");
        return;
    }
    Song* temp = head;
    while (temp != NULL) {
        printf("Now playing: %s by %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

// Function to free the memory allocated for the playlist
void freePlaylist(Song* head) {
    Song* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Song* playlist = NULL;

    // Add songs to the playlist
    addSong(&playlist, "Song 1", "Artist 1");
    addSong(&playlist, "Song 2", "Artist 2");
    addSong(&playlist, "Song 3", "Artist 3");

    // Display the playlist
    displayPlaylist(playlist);

    // Play the songs
    playSongs(playlist);

    // Free the memory
    freePlaylist(playlist);

    return 0;
}