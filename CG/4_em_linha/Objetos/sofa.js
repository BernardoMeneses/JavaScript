import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function createSofa() {
    const sofa = new THREE.Group();

    const textureLoader = new THREE.TextureLoader();
    const fabricTexture = textureLoader.load('./Imagens/sofaFabric.jpg'); // Substitua pelo caminho da sua textura
    const woodTexture = textureLoader.load('./Imagens/woodTexture'); // Substitua pelo caminho da sua textura

    const sofaMaterial = new THREE.MeshPhongMaterial({ map: fabricTexture });
    const woodMaterial = new THREE.MeshPhongMaterial({ map: woodTexture });

    // Base do sofá
    const sofaBase = new THREE.Mesh(
        new THREE.BoxGeometry(10, 1, 4),
        sofaMaterial
    );
    sofaBase.position.set(0, 0.5, 0);
    sofa.add(sofaBase);

    // Encosto do sofá
    const backrest = new THREE.Mesh(
        new THREE.BoxGeometry(10, 4, 1),
        sofaMaterial
    );
    backrest.position.set(0, 2.5, -1.5);
    sofa.add(backrest);

    // Braços do sofá
    const armrestGeometry = new THREE.BoxGeometry(1, 3, 4);
    const leftArmrest = new THREE.Mesh(armrestGeometry, sofaMaterial);
    leftArmrest.position.set(-4.5, 1.5, 0);
    sofa.add(leftArmrest);

    const rightArmrest = new THREE.Mesh(armrestGeometry, sofaMaterial);
    rightArmrest.position.set(4.5, 1.5, 0);
    sofa.add(rightArmrest);

    // Almofadas do sofá
    const cushionGeometry = new THREE.BoxGeometry(9.5, 0.75, 3.5);
    const seatCushion = new THREE.Mesh(cushionGeometry, sofaMaterial);
    seatCushion.position.set(0, 1.25, 0);
    sofa.add(seatCushion);

    const backCushionGeometry = new THREE.BoxGeometry(9.5, 2, 0.75);
    const backCushion = new THREE.Mesh(backCushionGeometry, sofaMaterial);
    backCushion.position.set(0, 3, -1.25);
    sofa.add(backCushion);

    // Pernas do sofá
    const legGeometry = new THREE.BoxGeometry(0.5, 1, 0.5);
    const positions = [
        { x: -4.5, z: -1.75 }, { x: 4.5, z: -1.75 },
        { x: -4.5, z: 1.75 }, { x: 4.5, z: 1.75 }
    ];

    positions.forEach(pos => {
        const leg = new THREE.Mesh(legGeometry, woodMaterial);
        leg.position.set(pos.x, -0.5, pos.z);
        sofa.add(leg);
    });

    return sofa;
}



