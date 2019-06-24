void setupMPU();

void processAccelData();

void processGyroData();

void recordAccelRegisters();

void recordGyroRegisters();

void getAccForce(float& aX, float& aY, float& aZ);

void getGyroRotation(float& gX, float& gY, float& gZ);

void getAccRaw(long& aX, long& aY, long& aZ);

void getGyroRaw(long& gX, long& gY, long& gZ);
