#!/bin/bash

# Verzeichnis für den Build erstellen, falls es nicht existiert
BUILD_DIR="build"
mkdir -p "$BUILD_DIR"

# In das Build-Verzeichnis wechseln
cd "$BUILD_DIR" || exit

# CMake konfigurieren
echo "Configuring CMake..."
cmake ..

# Projekt bauen
echo "Building project..."
cmake --build .

# Überprüfen, ob der Build erfolgreich war
if [ $? -ne 0 ]; then
    echo "Build failed. Exiting."
    exit 1
fi

# Tests ausführen
echo "Running tests..."
./tests/developer_test

# Überprüfen, ob die Tests erfolgreich waren
if [ $? -ne 0 ]; then
    echo "Tests failed. Exiting."
    exit 1
fi

# Hauptanwendung ausführen
echo "Running main application..."
./app/main

# Überprüfen, ob die Hauptanwendung erfolgreich war
if [ $? -ne 0 ]; then
    echo "Main application failed. Exiting."
    exit 1
fi

echo "All tasks completed successfully!"
