void setupMPU();

void processAccelData();

void processGyroData();

void recordAccelRegisters();

void recordGyroRegisters();

void getAccForce(float& aX, long& aY, long& aZ);

void getGyroRotation(float& gX, long& gY, long& gZ);

void getAccRaw(long& aX, long& aY, long& aZ);

void getGyroRaw(long& gX, long& gY, long& gZ);
