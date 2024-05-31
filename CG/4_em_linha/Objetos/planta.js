import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function createPlanta(position = { x: 45, y: 0, z: 0 }, vasoTextureURL = './Skybox/vaso.jpg', plantaTextureURL = './Skybox/planta.jpg') {
    const textureLoader = new THREE.TextureLoader();
    const vasoTexture = textureLoader.load(vasoTextureURL);
    const plantaTexture = textureLoader.load(plantaTextureURL);

    const vasoMaterial = new THREE.MeshPhongMaterial({ map: vasoTexture });
    const plantaMaterial = new THREE.MeshPhongMaterial({ map: plantaTexture });

    const vasoGeometry = new THREE.CylinderGeometry(5, 5, 10, 32);
    const plantaGeometry = new THREE.ConeGeometry(5, 20, 32);

    const vaso = new THREE.Mesh(vasoGeometry, vasoMaterial);
    vaso.position.set(position.x, position.y, position.z);

    const planta = new THREE.Mesh(plantaGeometry, plantaMaterial);
    planta.position.set(position.x, position.y + 10, position.z);

    const group = new THREE.Group();
    group.add(vaso);
    group.add(planta);

    return group;
}
