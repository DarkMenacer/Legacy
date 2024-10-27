import { BaseEntity, Column, CreateDateColumn, Entity, ManyToMany, OneToMany, PrimaryColumn } from "typeorm";
import { Home } from "./Home";

@Entity("dog_table")
export class Dog extends BaseEntity { //also supports inheritance
	@PrimaryColumn({ type: "text" }) dog_name: string;

	@Column({ type: "int", nullable: false }) age: number;

	@Column({ type: "bool", name: "bhondu_ka", default: true }) is_bhondu: boolean;

    @OneToMany(() => Home, (home) => home.dog) homes: Home[];

    @ManyToMany(() => Home) sharing_homes: Home[];
    //Special Columns
	// @CreateDateColumn
	// @UpdateDateColumn
	// @DeleteDateColumn
	// @VersionColumn
}
